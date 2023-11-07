#include "cmd.hpp"
#include "client.hpp"
#include "channel.hpp"


void cmd::privmsgToChannel(string arg, string inputmsg) {
	vector<Channel *>::iterator	iter;
	string						msg;
	Client 						*me = searchClient(_clntSock);

	if (!me)
		return ;
	for (iter = _chList.begin(); iter != _chList.end(); iter++)	{
		if ((*iter)->getChannelName() == arg) {
			vector<Client *> members = (*iter)->getUsers();
			if (!((*iter)->isClientInChannel(me)) && !(*iter)->getChNFlag())
			{
				/* 메세지를 보내려는 client가 해당 채널에 없는 경우 +n 이 안된 채널이면 보낼 수 없다 */
				msg = ":irc.local 404 " + me->getNickname() + " " + arg \
					   + " :You cannot send external messages to this channel whilst the +n (noextmsg) mode is set.\r\n";
				send(_clntSock, msg.c_str(), msg.size(), 0);
			}
			else
			{
				for (int i = 0; i < (int)members.size(); i++)
				{
					msg = ":" + me->getNickname() + "!" + me->getUserName() + "@" + me->getIP() \
						   + " PRIVMSG " + arg + " " + inputmsg + "\r\n";
					if (members[i]->getSock() != _clntSock)
						send(members[i]->getSock(), msg.c_str(), msg.size(), 0);
				}
			}
			return ;
		}
	}
	noSuchChannel(arg);
}

void cmd::privmsgToClient(string arg, string inputmsg)
{
	vector<Client *>::iterator	iter;
	string						msg;
	Client						*me = searchClient(_clntSock);

	for (iter = _clntList.begin(); iter != _clntList.end(); iter++) {
		if ((*iter)->getNickname() == arg){
			msg = ":" + me->getNickname() + "!" + me->getUserName() + "@" + me->getIP() \
				   + " PRIVMSG " + arg + " " + inputmsg + "\r\n";
			send((*iter)->getSock(), msg.c_str(), msg.size(), 0);
			return ;
		}
	}
	noSuchNick(arg);
}

void cmd::privmsg(string arg) {
	string line;
	stringstream tmp(arg);

	if (arg.empty())
		return ;
	tmp >> arg;
	getline(tmp, line, static_cast<char>(EOF));
	line.erase(0, 1);
	if (arg[0] == '#')
		privmsgToChannel(arg, line);
	else
		privmsgToClient(arg, line);
}
