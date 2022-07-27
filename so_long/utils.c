#include "solong.h"

char	*ft_strjoin_without_NL(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (j < s1_len && s1[j] != '\n')
		str[i++] = s1[j++];
	j = 0;
	while (j < s2_len && s2[j] != '\n')
		str[i++] = s2[j++];
	str[i] = '\0';
	//free(s1);
	return (str);
}