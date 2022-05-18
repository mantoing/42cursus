#include "get_next_line_bonus.h"

char	*gline(char *save)
{
	char	*line;
	size_t	i;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i])
		++i;
	if (save[i] == '\n')
		++i;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i])
	{
		line[i] = save[i];
		++i;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);				
}

char	*read_files(int fd, char *save)
{
	ssize_t	bread;
	char	*buffer;
	char	*temp;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bread = read(fd, buffer, BUFFER_SIZE);
	while (bread > 0)
	{
		buffer[bread] = '\0';
		temp = save;
		save = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(save, '\n') || !save)
			break ;
		bread = read(fd, buffer, BUFFER_SIZE);	
	}
	free(buffer);
	buffer = NULL;
	if (bread < 0)
		return (NULL);
	return (save);		 
}

t_list	*search_fd(t_list *head, int fd)
{
	t_list	*list;

	list = head -> next;
	while (list)
	{
		if (list -> fd == fd)
			return (list);
		list = list ->next;	
	}
	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list -> fd = fd;
	list -> prev = head;
	list -> next = head -> next;
	if (head -> next)
		head -> next -> prev = list;
	head -> next = list;
	list -> save = NULL;
	return (list);		
}

char	*return_l(t_list **temp)
{
	char	*save_temp;
	char	*line;
	t_list	*list;

	list = *temp;
	if (!(list -> save))
		return (NULL);
	else if (!*(list -> save))
	{
		free(list -> save);
		list -> save = NULL;
		return (NULL);
	}
	line = gline(list -> save);
	if (!line)
		return (NULL);
	save_temp = list -> save;
	list -> save = ft_strdup(list -> save + ft_strlen(line));
	free(save_temp);
	save_temp = NULL;
	if (!list -> save)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	char 	*line;
	static t_list head;
	t_list	*list;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	list = search_fd(&head, fd);
	if (!list)
		return (NULL);
	list->save = read_files(fd, list->save);
	line = return_l(&list);
	if (!line)
	{
		list -> prev -> next = list -> next;
		if (list -> next)
			list -> next -> prev = list -> prev;
		free(list);
		list = NULL;	
	}
	return (line);
}
