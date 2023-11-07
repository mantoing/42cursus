#include "channel.hpp"
#include "client.hpp"
#include <cstdlib>

Channel::Channel(std::string channelName) :
	_channelName(channelName),
	_passWord(""),
	_topic(""),
	_userLimit(-1), _chTime(saveTime()), 
	_kflag(false), _iflag(false), _tflag(true), _lflag(false), _nflag(true)
{}

Channel::Channel(std::string channelName, std::string password) :
	_channelName(channelName),
	_passWord(password),
	_topic(""),
	_userLimit(-1), _chTime(saveTime()), 
	_kflag(false), _iflag(false), _tflag(true), _lflag(false), _nflag(true)
{}

Channel::~Channel() {}

void	Channel::addUser(Client *client)
{
	for (std::vector<Client *>::iterator it = _users.begin(); it != _users.end(); it++)
	{
		if (client == *(it))
			return ;
	}
	_users.push_back(client);
}

void	Channel::delUser(Client *client)
{
	for (std::vector<Client *>::iterator it = _users.begin(); it != _users.end(); it++)
	{
		if ((*it) == client)
		{
			_users.erase(it);
			break ;
		}
	}
}

bool	Channel::isClientInChannel(Client *client)
{
	for (std::vector<Client *>::iterator it = _users.begin(); it != _users.end(); it++)
		if ((*it) == client)
			return (true);
	return (false);
}

void	Channel::addOpUser(Client *client)
{
	for (std::vector<Client *>::iterator it = _opUsers.begin(); it != _opUsers.end(); it++)
	{
		if (client == *(it))
			return ;
	}
	_opUsers.push_back(client);
}

void	Channel::delOpUser(Client *client)
{
	for (std::vector<Client *>::iterator it = _opUsers.begin(); it != _opUsers.end(); it++)
	{
		if ((*it) == client)
		{
			_opUsers.erase(it);
			break ;
		}
	}
}

bool	Channel::isClientOp(Client *client)
{
	for (std::vector<Client *>::iterator it = _opUsers.begin(); it != _opUsers.end(); it++)
		if ((*it) == client)
			return (true);
	return (false);
}

void	Channel::addInviteUser(Client *client)
{
	for (std::vector<Client *>::iterator it = _inviteUsers.begin(); it != _inviteUsers.end(); it++)
	{
		if (client == *(it))
			return ;
	}
	_inviteUsers.push_back(client);
}

void	Channel::delInviteUser(Client *client)
{
	for (std::vector<Client *>::iterator it = _inviteUsers.begin(); it != _inviteUsers.end(); it++)
	{
		if ((*it) == client)
		{
			_inviteUsers.erase(it);
			break ;
		}
	}
}

bool	Channel::isClientInvite(Client *client)
{
	for (std::vector<Client *>::iterator it = _inviteUsers.begin(); it != _inviteUsers.end(); it++)
		if ((*it) == client)
			return (true);
	return (false);
}

std::string	Channel::saveTime()
{
	long long	ltime = static_cast<long long>(time(NULL));
	std::string stime = "";
	char	c;

	while (ltime / 10)
	{
		c = '0' + ltime % 10;
		stime.insert(0, 1, c);
		ltime /= 10;
	}
	c = '0' + ltime % 10;
	stime.insert(0, 1 ,c);
	return stime;
}

void	Channel::printUsers()
{
	std::cout << "users(" << _users.size() << ") : ";
	for (std::vector<Client *>::iterator it = _users.begin(); it != _users.end(); it++)
		std::cout << (*it)->getNickname() << " ";
	std::cout << std::endl;
}

void	Channel::printOpUsers()
{
	std::cout << "opUsers(" << _opUsers.size() << ") : ";
	for (std::vector<Client *>::iterator it = _opUsers.begin(); it != _opUsers.end(); it++)
		std::cout << (*it)->getNickname() << " ";
	std::cout << std::endl;
}

void	Channel::printInviteUsers()
{
	std::cout << "inviteUsers(" << _inviteUsers.size() << ") : ";
	for (std::vector<Client *>::iterator it = _inviteUsers.begin(); it != _inviteUsers.end(); it++)
		std::cout << (*it)->getNickname() << " ";
	std::cout << std::endl;
}

void	Channel::clearClient(Client *client)
{
	for (std::vector<Client *>::iterator it = _users.begin(); it != _users.end(); it++)
	{
		if ((*it) == client)
		{
			_users.erase(it);
			break ;
		}
	}
	for (std::vector<Client *>::iterator it = _opUsers.begin(); it != _opUsers.end(); it++)
	{
		if ((*it) == client)
		{
			_opUsers.erase(it);
			break ;
		}
	}
	for (std::vector<Client *>::iterator it = _inviteUsers.begin(); it != _inviteUsers.end(); it++)
	{
		if ((*it) == client)
		{
			_inviteUsers.erase(it);
			break ;
		}
	}
}

void	Channel::setChCreatTime(const std::string time)
{
	_chTime = time;
}

void	Channel::setTopicTime(const std::string time)
{
	_topicTime = time;
}

void	Channel::setInviteOnlyFlag(const bool flag)
{
	_iflag = flag;
}

void	Channel::setChPassFlag(const bool flag)
{
	_kflag = flag;
}

void	Channel::setChTopicFlag(const bool flag)
{
	_tflag = flag;
}

void	Channel::setChLimitFlag(const bool flag)
{
	_lflag = flag;
}

void	Channel::setChNFlag(const bool flag)
{
	_nflag = flag;
}

void	Channel::setPassWord(const std::string passWord)
{
	_passWord = passWord;
}

void	Channel::setUserLimit(const int limit)
{
	_userLimit = limit;
}

void	Channel::setTopic(const std::string topic)
{
	_topic = topic;
}

void	Channel::setTopicMaker(const std::string name)
{
	_topicMaker = name;
}

std::string	Channel::getTopic()
{
	return (_topic);
}

std::string	Channel::getTopicMaker()
{
	return (_topicMaker);
}

std::string	Channel::getOption(Client *client)
{
	std::string	opt = "+";
	std::string	key = "<key>";
	std::string	limit = "";
	int			lim = _userLimit;

	if (_iflag)
		opt += "i";
	if (_kflag)
		opt += "k";
	if (_lflag)
		opt += "l";
	if (_nflag)
		opt += "n";
	if (_tflag)
		opt += "t";

	char	c;
	while (_lflag && lim / 10)
	{
		c = '0' + lim % 10;
		limit.insert(0, 1, c);
		lim /= 10;
	}
	c = '0' + lim % 10;
	limit.insert(0, 1 ,c);

	if (isClientInChannel(client))
		key = _passWord;

	if (_kflag && _lflag)
		opt = opt + " " + key + " :" + limit;
	else if (_kflag)
		opt = opt + " :" + key;
	else if (_lflag)
		opt = opt + " :" + limit;
	else
		opt = ":" + opt;

	return (opt);
}

std::string	Channel::getUsersName()
{
	std::string	users = "";

	for (std::vector<Client *>::iterator it = _users.begin(); it != _users.end(); it++)
	{
		if (isClientOp((*it)))
			users += "@" + ((*it)->getNickname() + " ");
		else
			users += ((*it)->getNickname() + " ");
	}
	users.erase(users.size() - 1, 1);
	return (users);
}

const std::string&	Channel::getChannelName() const
{
	return (_channelName);
}

const std::string&	Channel::getPassWord() const
{
	return (_passWord);
}

int	Channel::getUserLimit() const
{
	return (_userLimit);
}

const std::vector<Client *>&	Channel::getUsers() const
{
	return (_users);
}

bool Channel::getInviteOnlyFlag() const
{
	return (_iflag);
}
bool Channel::getChPassFlag() const
{
	return (_kflag);
}
bool Channel::getChTopicFlag() const
{
	return (_tflag);
}

bool Channel::getChLimitFlag() const
{
	return (_lflag);
}

bool Channel::getChNFlag() const
{
	return (_nflag);
}

std::string	Channel::getChannelTime() const
{
	return (_chTime);
}

std::string Channel::getTopicTime() const
{
	return (_topicTime);
}
