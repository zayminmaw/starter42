/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:46:31 by zmin              #+#    #+#             */
/*   Updated: 2025/08/27 19:51:24 by zmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Calculates the length of a string.
** 
** Parameters:
**   s - The string to measure (null-terminated)
** 
** Return:
**   Returns the number of characters before the null terminator.
** 
** Edge cases:
**   - Returns 0 for empty string
**   - Undefined behavior if s is NULL (no null check)
**   - Does not count the null terminator
*/
size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c])
	{
		c++;
	}
	return (c);
}
