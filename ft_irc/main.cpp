#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string>
#include <vector>
#define BUF_SIZE 100
#define EPOLL_SIZE 50

#include "server.hpp"
#include "client.hpp"

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Usage: " << argv[0] << " <port> <pass>" << std::endl;
		exit(1);
	}
	Server _server(atoi(argv[1]), argv[2]);
	_server.serverInit();
	_server.serverStart();
	return (0);
}
