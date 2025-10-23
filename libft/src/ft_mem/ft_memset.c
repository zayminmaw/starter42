/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:16:24 by zmin              #+#    #+#             */
/*   Updated: 2025/08/27 20:24:09 by zmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Fills a block of memory with a specified byte value.
** 
** Parameters:
**   s - Pointer to the memory area to fill
**   c - Value to set (as int, but used as unsigned char)
**   n - Number of bytes to fill
** 
** Return:
**   Returns the original pointer s.
** 
** Edge cases:
**   - If n is 0, no bytes are modified
**   - The byte value c is converted to unsigned char
**   - Returns the original pointer for convenience in chaining operations
*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *) s;
	while (n > 0)
	{
		*(tmp++) = (unsigned char) c;
		n--;
	}
	return (s);
}
