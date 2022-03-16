/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonseoyun <wonseoyun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:03:46 by wonseoyun         #+#    #+#             */
/*   Updated: 2022/03/16 17:18:20 by wonseoyun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
  size_t  i;

  if (!dest && !src)
    return (0);
  i = 0;
  while (i < n)
  {
    *(char *)(dest + i) = *(char *)(src + i);
    i++;
  }
  return (dest); 
}