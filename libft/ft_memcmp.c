/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonseoyun <wonseoyun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:41:54 by wonseoyun         #+#    #+#             */
/*   Updated: 2022/03/16 17:46:15 by wonseoyun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int ft_memcmp(void *s1, void *s2, size_t len)
{
  unsigned char *p1;
  unsigned char *p2;

  p1 = (unsigned char *)s1;
  p2 = (unsigned char *)s2;
  while (len--)
  {
    if (*p1 != *p2)
      return (*p1 - *p2);
    p1++;
    p2++;  
  }
  return (0);
}