#include "get_next_line.h"

char	*gline(char *save)
{
	char	*line;
	size_t	i;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i] != '\n' || save[i])
		++i;
	if (save[i] == '\n')
		++i;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] != '\n' || save[i])
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

char	*get_next_line(int fd)
{
	char	*line;
	static char	*save;
	char	*temp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	save = read_files(fd, save);
	if (!save)
		return (NULL);
	if (*save)
	{
		line = gline(save);
		if (!line)
			return (NULL);
		temp = save;
		save = ft_strdup(save + ft_strlen(line));
		free(temp);
		temp = NULL;
		if (!save)
			return (NULL);
		return (line);	
	}
	free(save);
	save = NULL;
	return (NULL);
}