#include "cmd.hpp"
#include "channel.hpp"
#include "client.hpp"

void	cmd::who(string arg)
{
	Channel	*ch;
	Client	*client;
	Client	*me;
	string	msg;
	string	status;

	me = searchClient(_clntSock);
	if (!me)
		return ;
	ch = searchChannel(arg);
	if (!ch)
	/* who <client_name> */
	{
		client = searchClient(arg);
		if (!client)
		/* client_namet channel_name 둘다 아닌 경우 */
			msg = ":irc.local 315 " + me->getNickname() + " " + arg + " :End of /WHO list.\r\n";
		/* client_name 인 경우 */
		else
		{
			string	lastJoinChannel;

			if (client->getCreated())
				status = "H";
			ch = client->getLastJoinChannel();
			if (!ch)
				lastJoinChannel = "*";
			else
			{
				lastJoinChannel = ch->getChannelName();
				if (ch->isClientOp(client))
					status += "@";
			}

			msg = ":irc.local 352 " + me->getNickname() + " " + lastJoinChannel \
				   + " " + client->getUserName() + " 127.0.0.1 irc.local " \
				   + client->getNickname() + " " + status + " :0 " + client->getRealName() + "\r\n" \
				   + ":irc.local 315 " + me->getNickname() + " " \
				   + client->getNickname() + " :End of /WHO list.\r\n";
		}
	}
	else
	/* who <channel_name> */
	{
		if (!ch->isClientInChannel(me))
		/* me 가 해당 channel 에 없는 경우 */
			msg = ":irc.local 315 " + me->getNickname() + " " + ch->getChannelName() + " :End of /WHO list.\r\n";
		else
		/* 정상 적으로 who <channel_name> 이 실행 되는 경우 */
		{
			vector<Client *> users = ch->getUsers();
	
			msg = "";
			for (vector<Client *>::iterator it = users.begin(); it != users.end(); it++)
			{
				if ((*it)->getCreated())
					status = "H";
				if (ch->isClientOp((*it)))
					status += "@";
				msg += (":irc.local 352 " + me->getNickname() + " " + ch->getChannelName() \
						+ " " + (*it)->getUserName() + " 127.0.0.1 irc.local " \
						+ (*it)->getNickname() + " " + status + " :0 " + (*it)->getRealName() + "\r\n");
			}
			msg += ":irc.local 315 " + me->getNickname() + " " + ch->getChannelName() + " :End of /WHO list.\r\n";
		}
	}
	send(_clntSock, msg.c_str(), msg.size(), 0);
}
