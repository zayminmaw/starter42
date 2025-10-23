/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmin <zmin@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 22:32:02 by zmin              #+#    #+#             */
/*   Updated: 2025/09/10 22:56:05 by zmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs a single character for ft_printf.
** 
** Parameters:
**   c - The character to output
** 
** Return:
**   Returns 1 (number of characters written).
** 
** Edge cases:
**   - Writes to stdout (fd 1)
**   - Always returns 1
*/
int	pf_putchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

/*
** Outputs a string for ft_printf.
** 
** Parameters:
**   str - The string to output (null-terminated)
** 
** Return:
**   Returns the number of characters written.
** 
** Edge cases:
**   - Outputs "(null)" if str is NULL
**   - Returns 6 for NULL string
**   - Returns string length otherwise
*/
int	pf_putstr(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
