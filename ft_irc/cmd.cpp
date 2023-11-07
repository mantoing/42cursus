#include "cmd.hpp"
#include "client.hpp"
#include "channel.hpp"

cmd::cmd(int clntSock, char *buf, int strlen, string servpass, vector<Client *> &clntList, vector<Channel *> &chList, bool& quit) : 
	_clntSock(clntSock), _clntList(clntList), _chList(chList), _servPass(servpass), _quit(quit)
{
	string			input(buf, strlen);
	string			line;
	size_t			start = 0;
	size_t			pos;
	content			content;

	while ((pos = input.find("\r\n", start)) != string::npos)
	{
		line = input.substr(start, pos - start);
		start = pos + 2;
		stringstream	tmp(line);
		tmp >> line;
		content.cmd = line;
		if (!tmp.eof())
		{
			getline(tmp, line, static_cast<char>(EOF));
			line.erase(0, 1);
		}
		else
			line = "";
		content.arg = line;
		_content.push_back(content);
		if (pos + 2 == input.size() - 1)
			break ;
	}
}

cmd::~cmd() {}

vector<string> *cmd::splitCmd(string &str) {
	vector<string> *tokens = new vector<string>;
	istringstream	iss(str);
	string token;
	while (iss >> token) {
		(*tokens).push_back(token);
	}
	return tokens;
}

Client	*cmd::searchClient(int sock)
{
	for (vector<Client *>::iterator it = _clntList.begin(); it != _clntList.end(); it++)
	{
		if ((*it)->getSock() == sock)
			return (*it);
	}
	return (NULL);
}

Client	*cmd::searchClient(string name)
{
	for (vector<Client *>::iterator it = _clntList.begin(); it != _clntList.end(); it++)
	{
		if ((*it)->getNickname() == name)
			return (*it);
	}
	return (NULL);
}

Channel	*cmd::searchChannel(string channelName)
{
	for (vector<Channel *>::iterator it = _chList.begin(); it != _chList.end(); it++)
		if ((*it)->getChannelName() == channelName)
			return (*it);
	return (NULL);
}

int cmd::parsecommand() {
	Client *me = searchClient(_clntSock);
	for (vector<content>::iterator it = _content.begin(); it != _content.end(); it++)
	{
		if ((*it).cmd == "PASS")
			pass((*it).arg);
		else if ((*it).cmd == "NICK")
			nick((*it).arg);
		else if ((*it).cmd == "USER")
			user((*it).arg);
		else if ((*it).cmd == "PING")
			ping();
		else if (me->getCreated() && me->getIsValidNick())
		{
			if ((*it).cmd == "JOIN")
				join((*it).arg);
			else if ((*it).cmd == "PRIVMSG")
				privmsg((*it).arg);
			else if ((*it).cmd == "TOPIC")
				topic((*it).arg);
			else if ((*it).cmd == "QUIT")
				quit((*it).arg);
			else if ((*it).cmd == "MODE")
				mode((*it).arg);
			else if ((*it).cmd == "KICK")
				kick((*it).arg);
			else if ((*it).cmd == "PART")
				part((*it).arg);
			else if ((*it).cmd == "INVITE")
				invite((*it).arg);
			else if ((*it).cmd == "WHO")
				who((*it).arg);
			else if ((*it).cmd == "WHOIS")
				whois((*it).arg);
		}
	}
	emptyChannelClear();
	return 0;
}

void	cmd::emptyChannelClear()
{
	vector<Channel *>::iterator it = _chList.begin();
	while (it != _chList.end())
	{
		if ((*it)->getUsers().size() == 0)
			_chList.erase(it);
		else
			it++;
	}
}

Channel	*cmd::addChannel(string name)
{
	Channel *newChannel = new Channel(name);
	if (!newChannel)
	{
		cout << "Error: cmd::addChannel: new Channel()" << endl;
		return (NULL);
	}
	_chList.push_back(newChannel);
	return (newChannel);
}

void	cmd::delChannel(Channel *channel)
{
	for (vector<Channel *>::iterator it = _chList.begin(); it != _chList.end(); it++)
	{
		if (channel == (*it))
		{
			delete (*it);
			_chList.erase(it);
			break ;
		}
	}
}

Client	*cmd::addClient(int sock)
{
	Client *newClient = new Client(sock);
	if (!newClient)
	{
		cout << "Error: cmd::addClient: new Client()" << endl;
		return (NULL);
	}
	_clntList.push_back(newClient);
	return (newClient);
}

void	cmd::delClient(Client *client)
{
	for (vector<Client *>::iterator it = _clntList.begin(); it != _clntList.end(); it++)
	{
		if (client == (*it))
		{
			delete (*it);
			_clntList.erase(it);
			break ;
		}
	}
}

void	cmd::printContent(const vector<content>& contents)
{
	for (vector<content>::const_iterator it = contents.begin(); it != contents.end(); it++)
		cout << "CMD : " << (*it).cmd << ", ARG : " << (*it).arg << endl;
}

const vector<content>& cmd::getContent() const
{
	return (_content);
}

void	cmd::setQuit(bool val)
{
	_quit = val;
}
