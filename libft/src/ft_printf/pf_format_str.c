/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmin <zmin@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 22:22:12 by zmin              #+#    #+#             */
/*   Updated: 2025/09/10 22:56:26 by zmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Processes format specifiers for ft_printf.
** 
** Parameters:
**   args - va_list containing variable arguments
**   type - The format specifier character
** 
** Return:
**   Returns the number of characters printed for this specifier.
** 
** Edge cases:
**   - Handles: c, s, d, i, u, %, x, X, p
**   - Extracts appropriate argument type based on specifier
**   - Returns character count from helper functions
**   - Routes to appropriate print function based on type
*/
int	pf_format_str(va_list args, const char type)
{
	int	p_count;

	p_count = 0;
	if (type == 'c')
		p_count += pf_putchar(va_arg(args, int));
	else if (type == 's')
		p_count += pf_putstr(va_arg(args, char *));
	else if (type == 'd' || type == 'i')
		p_count += pf_putnbr(va_arg(args, int));
	else if (type == 'u')
		p_count += pf_putunbr(va_arg(args, unsigned int));
	else if (type == '%')
		p_count += pf_putchar('%');
	else if (type == 'x' || type == 'X')
		p_count += pf_puthex(va_arg(args, unsigned int), type);
	else if (type == 'p')
		p_count += pf_putptr(va_arg(args, void *));
	return (p_count);
}
