#include "cmd.hpp"
#include "client.hpp"

void	cmd::user(string arg)
{
	Client	*client = searchClient(_clntSock);
	stringstream	temp(arg);
	string			realname;
	string			username;
	string			ip;
	string			msg;

	if (!client)
		return ;
	if (!client->getCreated())
	{
		temp >> username;
		temp >> username;
		temp >> ip;
		temp >> realname;
		if (realname.size() > 1 && realname[0] == ':')
			realname.erase(0, 1);
	
		if (username.empty() || ip.empty() || realname.empty())
		{
			msg = "Error: parameters error\r\n";
			send(_clntSock, msg.c_str(), msg.size(), 0);
			return ;
		}
		client->setRealName(realname);
		client->setUserName(username);
		client->setIP(ip);
	}
}
