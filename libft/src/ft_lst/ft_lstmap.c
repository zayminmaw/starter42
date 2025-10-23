/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 23:31:43 by zmin              #+#    #+#             */
/*   Updated: 2025/09/01 21:01:31 by zmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Creates a new list by applying a function to each node's content.
** 
** Parameters:
**   lst - The first node of the source list
**   f   - Function to apply to each node's content (returns new content)
**   del - Function to delete content if allocation fails
** 
** Return:
**   Returns a pointer to the first node of the new list,
**   or NULL if allocation fails or parameters are invalid.
** 
** Edge cases:
**   - Returns NULL if lst, f, or del is NULL
**   - Returns NULL if allocation fails (clears partial list with del)
**   - Uses ft_lstnew to create new nodes
**   - Uses ft_lstadd_back to build new list
**   - Clears original list at the end (caution: may not be desired behavior)
**   - On allocation failure, cleans up new list before returning NULL
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_obj;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_obj = ft_lstnew(f(lst->content));
		if (!new_obj)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_obj);
		lst = lst->next;
	}
	ft_lstclear(&lst, del);
	return (new_lst);
}
