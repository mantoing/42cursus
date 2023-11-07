#ifndef SERVER_HPP
# define SERVER_HPP

# include <iostream>
# include <unistd.h>
# include <string>
# include <cstring>
# include <cstdlib>
# include <cstdio>
# include <vector>
# include <arpa/inet.h>
# include <sys/event.h>

# define BUF_SIZE 100
# define EPOLL_SIZE 50

class Client;
class Channel;

class Server
{
	private:
		int						_servSock;
		int						_port;
		std::string				_passWord;
		std::vector<Channel *>	_channelList;
		std::vector<Client *>	_clntList;
		bool					_quit;

	public:
		Server(int port, std::string pass);
		~Server();

		void	serverInit();
		void	serverStart();

		void	addChannel(std::string name);
		void	delChannel(Channel *channel);

		void	addClient(int sock);
		void	delClient(Client *client);
		void	delClient(int sock);

		Client	*searchClient(std::string name);
		Client	*searchClient(int sock);
		bool	checkConnect(int clntSock);
		

		/* getter func */
		int					getSock() const;
		int					getPort() const;
		const std::string&	getPass() const;

		/* setter func */
		void				setPass(const std::string pass);
};

#endif
