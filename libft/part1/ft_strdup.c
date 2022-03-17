/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 01:11:27 by wonseoyun         #+#    #+#             */
/*   Updated: 2022/03/17 16:47:45 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char *ft_strdup(const char *s1)
{
  size_t  len;
  size_t  i;
  char    *ret;

  len = ft_strlen(len);
  ret = malloc(sizeof(char) * (len + 1));
  if (!ret)
    return (NULL);
  i = 0;
  while (i < len)
  {
    ret[i] = s1[i];
    i++;
  }
  ret[i] = '\0';
  return (ret);  
}