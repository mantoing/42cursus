#include "cmd.hpp"
#include "client.hpp"
#include "channel.hpp"

void	cmd::quit(string arg)
{
	Client	*me = searchClient(_clntSock);
	string	msg;

	if (!me)
		return ;
	for (vector<Channel *>::iterator it = _chList.begin(); it != _chList.end(); it++)
		(*it)->clearClient(me);

	msg = "ERROR :Closing link: (" + me->getUserName() + "@127.0.0.1) [Quit: " + arg + "]\r\n";
	send(_clntSock, msg.c_str(), msg.size(), 0);

	msg = ":" + me->getNickname() + "!" + me->getUserName() + "@127.0.0.1 QUIT :Quit: " + arg + "\r\n";
	for (vector<Client *>::iterator it = _clntList.begin(); it != _clntList.end(); it++)
		if ((*it) != me)
			send((*it)->getSock(), msg.c_str(), msg.size(), 0);
	setQuit(true);
}
