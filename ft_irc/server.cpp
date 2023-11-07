#include "server.hpp"
#include "client.hpp"
#include "channel.hpp"
#include "cmd.hpp"
#include <fcntl.h>

Server::Server(int port, std::string pass) : _port(port), _passWord(pass), _quit(false) {}

Server::~Server() {}

void	Server::serverInit()
{
	struct sockaddr_in	servAddr;

	_servSock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(_port);

	fcntl(_servSock, F_SETFL, O_NONBLOCK);

	if (bind(_servSock, (struct sockaddr *)&servAddr, sizeof(servAddr)) == -1)
	{
		std::cout << "Error: bind()" << std::endl;
		exit(1);
	}

	if (listen(_servSock, 5) == -1)
	{
		std::cout << "Error: listen()" << std::endl;
		exit(1);
	}
}

void	Server::serverStart()
{
	int		eventCnt;
	socklen_t	addrSize;
	struct sockaddr_in	clntAddr;
	int	clntSock;

	char	buf[BUF_SIZE];
	int		strlen;
	int		i;

	int kq = kqueue();
	if (kq < 0) {
		std::cerr << "Failef to create kqueue" << std::endl;
		close(_servSock);
		return ;
	}

	struct kevent events[10];
	struct kevent change;

	EV_SET(&change, _servSock, EVFILT_READ, EV_ADD, 0, 0, NULL);

	if (kevent(kq, &change, 1, NULL, 0, NULL) < 0) {
		std::cerr << "Failed to register server socket with kqueue" << std::endl;
		close(_servSock);
		close(kq);
		return ;
	}

	while (1)
	{
		eventCnt = kevent(kq, NULL, 0, events, 10, NULL);

		if (eventCnt == -1)
		{
			std::cout << "Error: epoll_wait()" << std::endl;
			break;
		}
		for (i = 0; i < eventCnt; i++)
		{
			if ((int)events[i].ident == _servSock)
			{
				/* Add Client!! */
				clntSock = accept(_servSock, (struct sockaddr *)&clntAddr, &addrSize);

				fcntl(clntSock, F_SETFL, O_NONBLOCK);
				EV_SET(&change, clntSock, EVFILT_READ, EV_ADD, 0, 0, NULL);
				if (kevent(kq, &change, 1, NULL, 0, NULL) < 0) {
					std::cerr << "Failed to register client socket with kqueue" << std::endl;
					close(clntSock);
				}

				/* linger socket */
				linger optval;
     			optval.l_onoff = 1;
     			optval.l_linger = 1;
				if (setsockopt(clntSock, SOL_SOCKET, SO_LINGER, &optval, sizeof(optval)) == -1)
				{
					std::cout << "Error: serverStart(): setsockopt()" << std::endl;
			        close(clntSock);
			        exit(1);
			    }
				
				addClient(clntSock);
				std::cout << "connected client: " << clntSock << std::endl;
			}
			else
			{
				strlen = recv(events[i].ident, buf, BUF_SIZE, 0);
				if (strlen <= 0)
				{
					EV_SET(&change, events[i].ident, EVFILT_READ, EV_DELETE, 0, 0, NULL);
					delClient(events[i].ident);
					std::cout << "closed client: " << events[i].ident << std::endl;
					close(events[i].ident);
				}
				else
				{
					cmd command(events[i].ident, buf, strlen, _passWord, _clntList, _channelList, _quit);
					command.printContent(command.getContent());
					command.parsecommand();
				}
				if (!checkConnect(events[i].ident) || _quit)
				{
					_quit = false;
					EV_SET(&change, events[i].ident, EVFILT_READ, EV_DELETE, 0, 0, NULL);
					delClient(events[i].ident);
					std::cout << "closed client: " << events[i].ident << std::endl;
					close(events[i].ident);
				}
			}
		}
	}
	close(_servSock);
	close(kq);
}

bool	Server::checkConnect(int clntSock)
{
	Client *me = searchClient(clntSock);
	if (!me)
		return (true);
	if (!me->getCreated() && !(me->getPass()).empty() && !(me->getNickname().empty()) && !(me->getUserName().empty()))
	{
		string	msg;
		if (!me->getIsValidNick())
		{
			msg = ":irc.local 433 * " + me->getNickname() + " :Nickname is already in use.\r\n";
			me->setNickname("");
			send(clntSock, msg.c_str(), msg.size(), 0);
		}
		else
		{
			if (me->getPass() != _passWord)
			{
				msg = ":irc.local ";
				msg = msg + "ERROR :Closing link: (" + me->getUserName() + "@127.0.0.1) [Access denied by configuration]\r\n";
				send(clntSock, msg.c_str(), msg.size(), 0);
				return (false);
			}
			else
			{
				string msg1 = "";
				string msg2 = "";
				me->setCreated(true);
				if (me->getIP() != "127.0.0.1")
				{
					msg1 = "NOTICE " + me->getNickname() +" :*** Could not resolve your hostname; using your IP address (127.0.0.1) instead.\r\n";
					me->setIP("127.0.0.1");
				}
				msg2 = ":irc.local 001 " + me->getNickname() + " :Welcome to the Localnet IRC Network " \
					   + me->getNickname() + "!" + me->getUserName() + "@127.0.0.1\r\n";
				send(clntSock, (msg1 + msg2).c_str(), (msg1 + msg2).size(), 0);
			}
		}
	}
	return (true);
}

void	Server::addChannel(std::string name)
{
	Channel *newChannel = new Channel(name);
	if (!newChannel)
	{
		std::cout << "Error: Server::addChannel: new Channel()" << std::endl;
		return ;
	}
	_channelList.push_back(newChannel);
}

void	Server::delChannel(Channel *channel)
{
	for (std::vector<Channel *>::iterator it = _channelList.begin(); it != _channelList.end(); it++)
	{
		if (channel == (*it))
		{
			delete (*it);
			_channelList.erase(it);
			break ;
		}
	}
}

Client	*Server::searchClient(int sock)
{
	for (vector<Client *>::iterator it = _clntList.begin(); it != _clntList.end(); it++)
	{
		if ((*it)->getSock() == sock)
			return (*it);
	}
	return (NULL);
}

Client	*Server::searchClient(string name)
{
	for (vector<Client *>::iterator it = _clntList.begin(); it != _clntList.end(); it++)
	{
		if ((*it)->getNickname() == name)
			return (*it);
	}
	return (NULL);
}

void	Server::addClient(int sock)
{
	Client *newClient = new Client(sock);
	if (!newClient)
	{
		std::cout << "Error: Server::addClient: new Client()" << std::endl;
		return ;
	}
	_clntList.push_back(newClient);
}

void	Server::delClient(Client *client)
{
	for (std::vector<Client *>::iterator it = _clntList.begin(); it != _clntList.end(); it++)
	{
		if (client == (*it))
		{
			delete ((*it));
			_clntList.erase(it);
			break ;
		}
	}
}

void	Server::delClient(int sock)
{
	for (std::vector<Client *>::iterator it = _clntList.begin(); it != _clntList.end(); it++)
	{
		if (sock == (*it)->getSock())
		{
			delete ((*it));
			_clntList.erase(it);
			break ;
		}
	}
}

int	Server::getSock() const
{
	return (_servSock);
}

int	Server::getPort() const
{
	return (_port);
}

const std::string&	Server::getPass() const
{
	return (_passWord);
}

