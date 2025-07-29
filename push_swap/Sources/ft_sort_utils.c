/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:05:10 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/24 17:13:18 by bkaras-g         ###   ########.fr       */
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

/**
 * @brief Finds and returns the node with the minimum value in a linked list.
 *
 * This function iterates through the given t_ps_list linked list and returns
 * a pointer to the node containing the smallest value, using index.
 *
 * @param list Pointer to the head of the linked list.
 * @return Pointer to the node with the minimum value, or NULL if the list is empty.
 */
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

/**
 * @brief Calculates the number of elements in a t_ps_list linked list.
 *
 * @param list Pointer to the head of the t_ps_list.
 * @return The number of elements in the list.
 */
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

/**
 * Calculates and assigns the cost for each element in the given list.
 *
 * The cost represents the number of operations required to move
 * each element to the top of the stack.
 *
 * @param list Pointer to the head of the t_ps_list linked list.
 */
void	ft_set_cost(t_ps_list *list)
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
		if (pos <= size / 2 + 1)
			list->cost = pos - 1;
		else
			list->cost = (size - pos + 1) * -1;
		list = list->next;
		pos++;
	}
}

/**
 * @brief Moves the specified element to the front of the linked list.
 *
 * This function takes a pointer to the head of a linked list and a pointer to an element
 * within that list. It moves the specified element to the front (head) of the list,
 * updating the necessary pointers. If the element is already at the front, no changes are made.
 *
 * @param head Double pointer to the head of the linked list.
 * @param elt Pointer to the element to move to the front.
 */
void	ft_move_to_front(t_ps_list **head, t_ps_list *elt, char *stack)
{
	if (!head || !*head || !(*head)->next)
		return ;
	while (elt->cost != 0)
	{
		if (elt->cost < 0)
		{
			if (!ft_strcmp(stack, "A"))
				rra(head);
			else
				rrb(head);
			elt->cost++;
		}
		else
		{
			if (!ft_strcmp(stack, "A"))
				ra(head);
			else
				rb(head);
			elt->cost--;
		}
	}
}
