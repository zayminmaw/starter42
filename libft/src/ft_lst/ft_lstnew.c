/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:36:13 by zmin              #+#    #+#             */
/*   Updated: 2025/09/01 21:01:39 by zmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Creates a new node for a linked list.
** 
** Parameters:
**   content - Pointer to the content to store in the node
** 
** Return:
**   Returns a pointer to the newly created node,
**   or NULL if allocation fails.
** 
** Edge cases:
**   - Returns NULL if malloc fails
**   - Sets next pointer to NULL
**   - Does not copy content, just stores the pointer
**   - content can be NULL
**   - Caller must free the node when done
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
