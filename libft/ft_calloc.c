/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonseoyun <wonseoyun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 00:51:47 by wonseoyun         #+#    #+#             */
/*   Updated: 2022/03/16 01:11:11 by wonseoyun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void  *ft_calloc(size_t count, size_t size)
{
  void  *ret;

  ret = malloc(count * size * sizeof(char));
  if (!ret)
    return (NULL);
  ft_bzero(ret, count * size);
  return (ret);  
}