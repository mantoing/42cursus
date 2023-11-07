#include "cmd.hpp"
#include "client.hpp"
#include "channel.hpp"

void cmd::execPart(string ch_name, string inputmsg)
{
	vector<Channel *>::iterator	iter;
	string						msg;
	Client						*me = searchClient(_clntSock);

	if (!me)
		return ;
	for (iter = _chList.begin(); iter != _chList.end(); iter++) {
		if ((*iter)->getChannelName() == ch_name) {
			vector<Client *> members = (*iter)->getUsers();
			if (!((*iter)->isClientInChannel(me))) {
				msg = ":irc.local 442 " + me->getNickname() + " " + ch_name + " :You're not on that channel!\r\n";
				send(_clntSock, msg.c_str(), msg.size(), 0);
				return ;
			}
			else {
				for (int i = 0; i < (int)members.size(); i++){
					if (inputmsg.empty())
						msg = ":" + me->getNickname() + "!" + me->getUserName() + "@" + me->getIP() + " PART :" + ch_name + "\r\n";
					else
						msg = ":" + me->getNickname() + "!" + me->getUserName() + "@" + me->getIP() + " PART " + ch_name + " " + inputmsg + "\r\n";
					send(members[i]->getSock(), msg.c_str(), msg.size(), 0);
				}
				(*iter)->delUser(me);
				(*iter)->delOpUser(me);
				(*iter)->delInviteUser(me);
				me->exitChannel((*iter)->getChannelName());
			}
			return ;
		}
	}
	noSuchChannel(ch_name);
}

void cmd::part(string arg)
{
	string line;
	stringstream tmp(arg);

	if (arg.empty())
		return ;
	tmp >> arg;
	getline(tmp, line, static_cast<char>(EOF));
	line.erase(0, 1);
	execPart(arg, line);
}
