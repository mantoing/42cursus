#ifndef MINITALK_H
# define MINITALK_H

# define ERROR -1

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

int	ft_putstr(char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int nb, int fd);
size_t	ft_strlen(char *str);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);

#endif