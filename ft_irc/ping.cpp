#include "cmd.hpp"
#include "client.hpp"
#include "channel.hpp"

void cmd::ping()
{
	string msg;

	msg = ":irc.local PONG irc.local :irc.local\r\n";
	send(_clntSock, msg.c_str(), msg.length(), 0);
	return ;
}
