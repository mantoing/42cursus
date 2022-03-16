/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonseoyun <wonseoyun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:28:49 by wonseoyun         #+#    #+#             */
/*   Updated: 2022/03/16 17:35:12 by wonseoyun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void *ft_memmove(void *dest, const void *src, size_t len)
{
  size_t  i;
  char *dest_c;

  if (!dest && !src)
    return (NULL);

  dest_c = (char *)dest;
  i = 0;
  if (dest > src)
  {
    while (len--)
      *(dest_c + len) = *(char *)(src + len);
  }
  else
  {
    while (len--)
      *dest_c++ = *(char *)src++;
  }
  return (dest);
}