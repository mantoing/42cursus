/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeywon <jaeywon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:03:13 by jaeywon           #+#    #+#             */
/*   Updated: 2022/03/15 16:59:58 by jaeywon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int ft_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
    {
        c = c + 32;
    }
    return (c);
}