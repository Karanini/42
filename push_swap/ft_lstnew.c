/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:17:49 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/23 17:01:14 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Creates a new node for a push_swap linked list.
 *
 * Allocates and initializes a new t_ps_list node with the given value. Index
 * and target position are initialized to -1.
 *
 * @param val The integer value to store in the node.
 * @return Pointer to the newly created t_ps_list node, or NULL on failure.
 */
t_ps_list	*ft_lstnew(int val)
{
	t_ps_list	*new;

	new = malloc(sizeof(t_ps_list));
	if (new == NULL)
		return (NULL);
	new->val = val;
	new->index = -1;
	new->target = NULL;
	new->cost = 0;
	new->next = NULL;
	return (new);
}
