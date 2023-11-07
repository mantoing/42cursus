#include "cmd.hpp"
#include "channel.hpp"
#include "client.hpp"
#include <cstdlib>

void	cmd::joinExistChannel(Client *me, Channel *ch, string pass)
{
	string	msg;
	string	msg2;
	string	msg3;
	string	channel_users;
	vector<Client *>	users;

	if (ch->isClientInvite(me))
	/* invite 받은 client인 경우 */
	{
		string	topicMsg = "";
		ch->addUser(me);
		me->joinChannel(ch);
		ch->delInviteUser(me);
		channel_users = ch->getUsersName();
		users = ch->getUsers();

		if (ch->getTopic().size() != 0)
		{
			Client	*topicer = searchClient(ch->getTopicMaker());
			if (!topicer)
				return ;
			topicMsg = ":irc.local 332 " + me->getNickname() + " " \
						+ ch->getChannelName() + " :" + ch->getTopic() + " \r\n" \
						+ ":irc.local 333 " + me->getNickname() + " " \
						+ ch->getChannelName() + " " + topicer->getNickname() + "!" \
						+ topicer->getUserName() + "@127.0.0.1 :" + ch->getTopicTime() + "\r\n";
		}
		msg = ":" + me->getNickname() + "!" + me->getUserName() \
			   + "@127.0.0.1 JOIN :" + ch->getChannelName() + "\r\n";
		msg2 = ":irc.local 353 " + me->getNickname() + " = " + ch->getChannelName() \
				+ " :" + channel_users + "\r\n";
		msg3 = ":irc.local 366 " + me->getNickname() + " " + ch->getChannelName() \
				+ " :End of /NAMES list.\r\n";
		send(_clntSock, (msg + topicMsg + msg2 + msg3).c_str(), (msg + topicMsg + msg2 + msg3).size(), 0);
		for (vector<Client *>::iterator it = users.begin(); it != users.end(); it++)
			if ((*it) != me)
				send((*it)->getSock(), msg.c_str(), msg.size(), 0);
	}
	else
	{
		if (ch->getChPassFlag() && ch->getChPassFlag() && pass != ch->getPassWord())
		/* password가 일치하지않는 경우 */
		{
			msg = ":irc.local 475 " + me->getNickname() + " " + ch->getChannelName() \
				   + " :Cannot join channel (incorrect channel key)\r\n";
			send(_clntSock, msg.c_str(), msg.size(), 0);
		}
		/* password가 일치하는 경우 */
		else
		{
			if (ch->getInviteOnlyFlag())
			/* channel이 invite only 인 경우 */
			{
				msg = ":irc.local 473 " + me->getNickname() + " " + ch->getChannelName() \
					   + " :Cannot join channel (invite only)\r\n";
				send(_clntSock, msg.c_str(), msg.size(), 0);
			}
			else
			{
				if (ch->getChLimitFlag() && static_cast<int>(ch->getUsers().size()) >= ch->getUserLimit())
				/* 유저제한을 넘는 경우 */
				{
					msg = ":irc.local 471 " + me->getNickname() + " " + ch->getChannelName() \
						   + " :Cannot join channel (channel is full)\r\n";
					send(_clntSock, msg.c_str(), msg.size(), 0);
				}
				else
				/* 정상 적으로 채널에 들어가는 경우 */
				{
					string	topicMsg = "";

					ch->addUser(me);
					me->joinChannel(ch);
					channel_users = ch->getUsersName();
					users = ch->getUsers();
					if (ch->getTopic().size() != 0)
					{
						Client	*topicer = searchClient(ch->getTopicMaker());
						if (topicer)
							return ;
						topicMsg = ":irc.local 332 " + me->getNickname() + " " \
									+ ch->getChannelName() + " :" + ch->getTopic() + " \r\n" \
									+ ":irc.local 333 " + me->getNickname() + " " \
									+ ch->getChannelName() + " " + topicer->getNickname() + "!" \
									+ topicer->getUserName() + "@127.0.0.1 :" + ch->getTopicTime() + "\r\n";
					}
					msg = ":" + me->getNickname() + "!" + me->getUserName() \
						   + "@127.0.0.1 JOIN :" + ch->getChannelName() + "\r\n";
					msg2 = ":irc.local 353 " + me->getNickname() + " = " + ch->getChannelName() \
							+ " :" + channel_users + "\r\n";
					msg3 = ":irc.local 366 " + me->getNickname() + " " + ch->getChannelName() \
							+ " :End of /NAMES list.\r\n";
					send(_clntSock, (msg + topicMsg + msg2 + msg3).c_str(), (msg + topicMsg + msg2 + msg3).size(), 0);
					for (vector<Client *>::iterator it = users.begin(); it != users.end(); it++)
						if ((*it) != me)
							send((*it)->getSock(), msg.c_str(), msg.size(), 0);
				}
			}
		}
	}
}

void	cmd::joinNewChannel(Client *me, string channel)
{
	Channel	*ch;
	string	msg;
	
	ch = addChannel(channel);
	if (!ch)
		exit(1);
	else
	{
		ch->addOpUser(me);
		ch->addUser(me);
		me->joinChannel(ch);
		msg = ":" + me->getNickname() + "!" + me->getUserName() \
			   + "@127.0.0.1 JOIN :" + ch->getChannelName() + "\r\n" 
			   + ":irc.local 353 " + me->getNickname() + " = " + ch->getChannelName() \
			   + " :" + "@" + me->getNickname() + "\r\n" \
			   + ":irc.local 366 " + me->getNickname() + " " + ch->getChannelName() \
			   + " :End of /NAMES list.\r\n"; send(_clntSock, msg.c_str(), msg.size(), 0);
	}
}


void	cmd::joinWithPass(vector<string> &chList, vector<string> &passList)
{
	vector<string>::iterator	channel = chList.begin();
	vector<string>::iterator	pass = passList.begin();

	Client	*me = searchClient(_clntSock);

	if (!me)
		return ;
	Channel	*ch;

	for (;channel != chList.end(); channel++)
	{
		ch = searchChannel((*channel));
		if (ch)
		/* 존재하는 채널에 들어가는 경우 */
			joinExistChannel(me, ch, (*pass));
		else
		/* 새로운 채널을 생성할때 */
			joinNewChannel(me, (*channel));
		pass++;
	}
}

void	cmd::joinNoPass(vector<string> &chList)
{
	vector<string>::iterator	channel = chList.begin();

	Client	*me = searchClient(_clntSock);
	Channel	*ch;

	if (!me)
		return ;
	for (;channel != chList.end(); channel++)
	{
		ch = searchChannel((*channel));
		if (ch)
		/* 존재하는 채널에 들어가는 경우 */
			joinExistChannel(me, ch, "");
		else
		/* 새로운 채널을 생성할때 */
			joinNewChannel(me, (*channel));
	}
}


void	cmd::join(string arg)
{
	stringstream	ss(arg);
	string			channels;
	string			passwords;
	vector<string>	chList;
	vector<string>	passList;
	size_t			start = 0;
	size_t			pos = 0;

	if (arg.empty())
		return ;

	/* 채널 이름들 ',' 기준으로 스플릿*/
	ss >> channels;
	while ((pos = channels.find(",", start)) != string::npos)
	{
		chList.push_back(channels.substr(start, pos - start));
		start = pos + 1;
	}
	chList.push_back(channels.substr(start, channels.size() - start));
	
	/* password들 ',' 기준으로 스플릿*/
	if (!ss.eof())
	{
		ss >> passwords;
		start = 0; pos = 0;
		while ((pos = passwords.find(",", start)) != string::npos)
		{
			passList.push_back(passwords.substr(start, pos - start));
			start = pos + 1;
		}
		passList.push_back(passwords.substr(start, passwords.size() - start));
	}

	if (passList.size())
		joinWithPass(chList, passList);
	else
		joinNoPass(chList);
}
