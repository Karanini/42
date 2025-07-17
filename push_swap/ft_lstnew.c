/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:17:49 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/15 15:27:07 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Creates a new node for a push_swap linked list.
 *
 * Allocates and initializes a new t_ps_list node with the given value,
 * index, and target position.
 *
 * @param val The integer value to store in the node.
 * @param index The index of the node in the list.
 * @param target The target position for sorting purposes.
 * @return Pointer to the newly created t_ps_list node, or NULL on failure.
 */
t_ps_list	*ft_lstnew(int val, size_t index, size_t target)
{
	t_ps_list	*new;

	new = malloc(sizeof(t_ps_list));
	if (new == NULL)
		return (NULL);
	new->val = val;
	new->index = index;
	new->target = target;
	new->cost_a = 0;
	new->cost_b = 0;
	new->next = NULL;
	return (new);
}
