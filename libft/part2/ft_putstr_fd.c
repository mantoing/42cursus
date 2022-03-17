/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:03:05 by jaeywon           #+#    #+#             */
/*   Updated: 2022/03/17 17:05:40 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void    ft_putstr_fd(char *str, int fd)
{
    size_t  size;

    if (fd < 0 || !str)
        return ;
    size = ft_strlen(str)
    write (fd, str, size);    
}