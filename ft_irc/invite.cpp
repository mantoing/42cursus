#include "cmd.hpp"
#include "channel.hpp"
#include "client.hpp"

void	cmd::invite(string arg)
{
	stringstream		ss(arg);
	string				userName;
	string				chName;

	string				channel_users;
	vector<Client *>	users;
	string				msg;
	Client				*client;
	Client				*me;
	Channel				*ch;

	if (arg.empty())
		return ;
	ss >> userName;
	ss >> chName;

	ch = searchChannel(chName);
	if (!ch)
	{
		noSuchChannel(chName);
		return ;
	}

	client = searchClient(userName);
	if (!client)
	{
		noSuchNick(userName);
		return ;
	}

	me = searchClient(_clntSock);
	if (!me)
		return ;
	if (!(ch->isClientInChannel(me)))
	{
		msg = ":irc.local 442 " + me->getNickname() + " " \
			   + ch->getChannelName() + " :You're not on that channel!\r\n";
		send(_clntSock, msg.c_str(), msg.size(), 0);
		}
	else
	{
		if (ch->isClientInvite(client))
		{
			msg = ":irc.local 443 " + me->getNickname() + " " \
				   + client->getNickname() + " " + ch->getChannelName() + " :is already on channel\r\n";
			send(_clntSock, msg.c_str(), msg.size(), 0);
		}
		else
		{
			ch->addInviteUser(client);
			channel_users = ch->getUsersName();
			users = ch->getUsers();
	
			/* 초대를 한 client에게 보내는 메세지 */
			msg = ":irc.local 341 " + me->getNickname() + " " \
				   + client->getNickname() + " :" + ch->getChannelName() + "\r\n";
			send(_clntSock, msg.c_str(), msg.size(), 0);
	
			/* 초대를 받은 client에게 보내는 메세지 */
			msg = ":irc.local NOTICE " + ch->getChannelName() \
					+ " :*** " + me->getNickname() + " invited " + client->getNickname() + " into the channel\r\n";
			send(client->getSock(), msg.c_str(), msg.size(), 0);
	
			/* 초대한 채널에 있는 client들에게 보내는 메세지 */
			msg = ":" + me->getNickname() + "!" + me->getUserName() \
				   + "@127.0.0.1 INVITE " + client->getNickname() + " :" + ch->getChannelName() + "\r\n";
			for (vector<Client *>::iterator it = users.begin(); it != users.end(); it++)
				if ((*it) != me)
					send((*it)->getSock(), msg.c_str(), msg.size(), 0);
		}
	}
}
