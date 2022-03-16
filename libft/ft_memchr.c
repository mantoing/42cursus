/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonseoyun <wonseoyun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:59:22 by wonseoyun         #+#    #+#             */
/*   Updated: 2022/03/16 18:02:07 by wonseoyun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void  ft_memchr(const void *ptr, int c, size_t len)
{
  unsigned char *ret;

  ret = (unsigned char *)ptr;
  while (len--)
  {
    if (*ret == (unsigned char)c)
      return (ret);
    else
      ret++;  
  }
  return (0);
}