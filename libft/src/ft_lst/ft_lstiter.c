/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 23:24:47 by zmin              #+#    #+#             */
/*   Updated: 2025/09/01 21:00:23 by zmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates through a linked list and applies a function to each node's content.
** 
** Parameters:
**   lst - The first node of the list
**   f   - Function to apply to each node's content
** 
** Return:
**   None (void function)
** 
** Edge cases:
**   - Safe to call on empty list (does nothing)
**   - f is called on each node's content in order
**   - Does not modify the list structure
**   - Undefined behavior if f is NULL (no null check)
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
