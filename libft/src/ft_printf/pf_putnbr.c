/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmin <zmin@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 19:33:51 by zmin              #+#    #+#             */
/*   Updated: 2025/09/10 22:55:50 by zmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs a signed integer for ft_printf.
** 
** Parameters:
**   nbr - The integer to output
** 
** Return:
**   Returns the number of characters printed.
** 
** Edge cases:
**   - Uses ft_itoa to convert int to string
**   - Handles negative numbers
**   - Handles INT_MIN correctly
**   - Frees allocated string after printing
*/
int	pf_putnbr(int nbr)
{
	char	*s_nbr;
	int		count;

	s_nbr = ft_itoa(nbr);
	count = pf_putstr(s_nbr);
	free(s_nbr);
	return (count);
}
