/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:05:10 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/23 14:42:26 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds and returns the node with the maximum value in a t_ps_list.
 *
 * This function iterates through the given linked list and returns a pointer
 * to the node containing the maximum value, using the index.
 * If the list is empty, it returns NULL.
 *
 * @param list Pointer to the head of the t_ps_list.
 * @return Pointer to the node with the maximum value,
	or NULL if the list is empty.
 */
t_ps_list	*ft_get_max(t_ps_list *list)
{
	t_ps_list	*max;

	if (!list || !list->next)
		return (NULL);
	max = list->next;
	while (list)
	{
		if (list->index > max->index)
			max = list;
		list = list->next;
	}
	return (max);
}

t_ps_list	*ft_get_min(t_ps_list *list)
{
	t_ps_list	*min;

	if (!list || !list->next)
		return (NULL);
	min = list->next;
	while (list)
	{
		if (list->index < min->index)
			min = list;
		list = list->next;
	}
	return (min);
}

size_t	ft_get_size(t_ps_list *list)
{
	size_t size;

	size = 0;
	if (!list)
		return (size);
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}

void	ft_get_cost(t_ps_list *list)
{
	size_t	size;
	size_t	pos;

	if (!list)
		return ;
	size = ft_get_size(list);
	list->cost = 0;
	list = list->next;
	pos = 2;
	while (list)
	{
		if (pos <= size / 2)
			list->cost = pos - 1;
		else
			list->cost = (size - pos + 1) * -1;
		list = list->next;
		pos++;
	}
}

void	ft_move_to_front(t_ps_list **head, t_ps_list *elt)
{
	if (!head || !*head || !(*head)->next)
		return ;
	while (elt->cost != 0)
	{
		if (elt->cost < 0)
		{
			rra(head);
			elt->cost++;
		}
		else
		{
			ra(head);
			elt->cost--;
		}
	}
}
