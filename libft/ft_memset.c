/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonseoyun <wonseoyun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:47:10 by wonseoyun         #+#    #+#             */
/*   Updated: 2022/03/16 16:51:02 by wonseoyun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void  *ft_memset(void *ptr, int b, size_t len)
{
  int i;
  unsigned char *ret;

  i = 0;
  ret = (unsigned char *)ptr;
  while (i < len)
  {
    ret[i] = (unsigned char *)b;
    i++;
  }
  return (ptr);
}