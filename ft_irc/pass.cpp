#include "cmd.hpp"
#include "client.hpp"

void	cmd::pass(string pass)
{
	string	msg;
	Client	*me = searchClient(_clntSock);

	if (!me)
		return ;
	if (!me->getCreated())
	{
		if (pass.empty())
		{
			msg = "Error: parameters error\r\n";
			send(_clntSock, msg.c_str(), msg.size(), 0);
			return ;
		}
		me->setPass(pass);
	}
}
