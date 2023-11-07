#include "cmd.hpp"
#include "channel.hpp"
#include "client.hpp"

void cmd::execKick(string ch_name, string nick)
{
	string						msg;
	string 						inputmsg;
	stringstream 				tmp(nick);
	vector<Channel *>::iterator	chiter;
	vector<Client *>::iterator	cliter;
	Client						*me = searchClient(_clntSock);

	if (!me)
		return ;
	tmp >> nick;
	getline(tmp, inputmsg, static_cast<char>(EOF));
	inputmsg.erase(0, 1);

	for (chiter = _chList.begin(); chiter != _chList.end(); chiter++) {
		if ((*chiter)->getChannelName() == ch_name) {
			for (cliter = _clntList.begin(); cliter != _clntList.end(); cliter++) {
				if ((*cliter)->getNickname() == nick) {
					vector<Client *> members = (*chiter)->getUsers();
					if (!(*chiter)->isClientInChannel(me)) {
						msg = ":irc.local 442 " + me->getNickname() + " " + ch_name + " :You're not on that channel!\r\n";
						send(_clntSock, msg.c_str(), msg.size(), 0);
						return ;
					}
					else if (!(*chiter)->isClientInChannel(*cliter)){
						msg = ":irc.local 441 " + me->getNickname() + " " + nick + " " + ch_name + " :They are not on that channel\r\n";
						send(_clntSock, msg.c_str(), msg.size(), 0);
						return ;
					}
					else if (!(*chiter)->isClientOp(me)) {
						msg = ":irc.local 482 " + me->getNickname() + " " + ch_name + " :You must be a channel operator\r\n";
						send(_clntSock, msg.c_str(), msg.size(), 0);
						return; 
					}
					else {
						for (int i = 0; i < (int)members.size(); i++) {
							msg = ":" + me->getNickname() + "!" + me->getUserName() + "@" + me->getIP() + " KICK " + ch_name + " " + nick + " " + inputmsg + "\r\n";
							send(members[i]->getSock(), msg.c_str(), msg.size(), 0);
						}
						(*chiter)->delUser(*cliter);
						(*chiter)->delOpUser(*cliter);
						(*cliter)->exitChannel(ch_name);
					}
					return ;
				}
			}
			noSuchNick(nick);
			return ;
		}
	}
	noSuchChannel(ch_name);
}

void cmd::kick(string arg)
{
	string line;
	stringstream tmp(arg);

	if (arg.empty())
		return ;
	tmp >> arg;
	getline(tmp, line, static_cast<char>(EOF));
	line.erase(0, 1);
	execKick(arg, line);
}
