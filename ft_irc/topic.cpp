#include "cmd.hpp"
#include "channel.hpp"
#include "client.hpp"

void cmd::settingtopic(string arg, string inputmsg) {
	vector<Channel *>::iterator	iter;
	string						topic;
	Client						*me = searchClient(_clntSock);

	if (!me)
		return ;
	for (iter = _chList.begin(); iter != _chList.end(); iter++) {
		if ((*iter)->getChannelName() == arg) {
			vector<Client *> members = (*iter)->getUsers();
			if (!((*iter)->isClientInChannel(me))) {
				topic = ":irc.local 442 " + me->getNickname() + " " + arg + " :You're not on that channel!\r\n";
				send(_clntSock, topic.c_str(), topic.size(), 0);
			}
			else {
				if ((*iter)->getChTopicFlag() == true){
					if (!((*iter)->isClientOp(me))) {
						topic = ":irc.local 482 " + me->getNickname() + " " + arg + " :You do not have access to change the topic on this channel\r\n";
						send(_clntSock, topic.c_str(), topic.size(), 0);
						return ;
					}
				}
				for (int i = 0; i < (int)members.size(); i++) {
					topic = ":" + me->getNickname() + "!" + me->getUserName() + "@" + me->getIP() + " TOPIC " + arg + " " + inputmsg + "\r\n";
					send(members[i]->getSock(), topic.c_str(), topic.size(), 0);
				}
				(*iter)->setTopicTime((*iter)->saveTime());
				(*iter)->setTopicMaker(me->getNickname());
				(*iter)->setTopic(inputmsg);
			}
			return ;
		}
	}
	noSuchChannel(arg);
}

void cmd::topic(string arg)
{
	string	msg;
	Client	*me = searchClient(_clntSock);

	if (!me)
		return ;
	if (arg.empty()) {
		msg = ":irc.local 461 " + me->getNickname() + " TOPIC " + ":Not enough parameters.\r\n";
		send(_clntSock, msg.c_str(), msg.size(), 0);
		return ;
	}
	string line;
	stringstream tmp(arg);
	tmp >> arg;
	getline(tmp, line, static_cast<char>(EOF));
	line.erase(0, 1);
	settingtopic(arg, line);
}
