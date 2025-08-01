/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:31:21 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/01 13:57:50 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_3_num(t_ps_list **head_a);
static void	ft_sort_5_num(t_ps_list **head_a, t_ps_list **head_b,
				size_t total_size);
static void	ft_sort_yolo_num(t_ps_list **head_a, t_ps_list **head_b);

void	ft_sort(t_ps_list **head_a, t_ps_list **head_b, size_t total_size)
{
	if (total_size == 1 || ft_is_sorted(*head_a))
		return ;
	else if (total_size == 2)
	{
		if ((*head_a)->index > (*head_a)->next->index)
			sa(head_a);
		return ;
	}
	else if (total_size == 3)
	{
		ft_sort_3_num(head_a);
		return ;
	}
	else if (total_size == 4 || total_size == 5)
	{
		ft_sort_5_num(head_a, head_b, total_size);
		return ;
	}
	else
		ft_sort_yolo_num(head_a, head_b);
}

/**
 * Checks if the linked list starting at head_a is sorted in ascending order.
 *
 * @param head_a Pointer to the head of the linked list to check.
 * @return 1 if the list is sorted, 0 otherwise.
 */
int	ft_is_sorted(t_ps_list *head_a)
{
	t_ps_list	*elt;

	elt = head_a;
	while (elt)
	{
		if (elt->next && elt->next->index != elt->index + 1)
			break ;
		elt = elt->next;
	}
	if (!elt)
		return (1);
	else
		return (0);
}

/**
 * Sorts a stack containing exactly three elements.
 *

* This function sorts the top three elements of the stack pointed to by `head_a`

* in ascending order using the allowed stack operations. It assumes that
the stack
 * contains exactly three nodes and modifies the stack in place.
 *
 * @param head_a Pointer to the pointer of the head of the stack (linked list).
 */
static void	ft_sort_3_num(t_ps_list **head_a)
{
	t_ps_list	*max;

	max = ft_get_max(*head_a);
	if (max == *head_a)
		ra(head_a);
	else if (max == (*head_a)->next)
		rra(head_a);
	if ((*head_a)->index > (*head_a)->next->index)
		sa(head_a);
}

/*
 * @brief sorts 4 to 5 numbers. 4 num : pushes the smallest to B then
 * ft_sort_3_num(A). 5 nums : pushes the 2 smallest to B then ft_sort_3_num(A)
 * while (i < total_size - 3) --> loops once with 4 nums and twice with 5.
 *
 * @param total_size the total numbers to sort (4 or 5 here)
 * @param head_a Double pointer to the head of the stack A.
 * @param head_b Double pointer to the head of the stack B.
 */
static void	ft_sort_5_num(t_ps_list **head_a, t_ps_list **head_b,
		size_t total_size)
{
	t_ps_list	*min;
	size_t		i;

	i = 0;
	while (i < total_size - 3)
	{
		ft_set_cost(*head_a);
		min = ft_get_min(*head_a);
		ft_move_to_front(head_a, min, "A");
		pb(head_a, head_b);
		i++;
	}
	ft_sort_3_num(head_a);
	pa(head_b, head_a);
	if (total_size == 5)
		pa(head_b, head_a);
}

/**
 * Sorts the elements in stack 'a' using a custom "yolo" sorting algorithm,
 * utilizing stack 'b' as auxiliary storage (actually mechanical turk algo).
 *
 * (1) pushing (total_size - 3) numbers to B and sorting the 3 that remain in A
 *
 * (2) setting cost and target for each number, then pushing from B to A the
 * cheapest number to move
 *
 * (3) setting cost of A numbers one last time to move the min of A to the top
 * using rr or rrr depending on its position in the stack
 *
 * @param head_a Pointer to the pointer of the head of stack 'a'.
 * @param head_b Pointer to the pointer of the head of stack 'b'.
 *
 * This function is intended for internal use and implements a specific
 * sorting strategy for the push_swap project.
 */
static void	ft_sort_yolo_num(t_ps_list **head_a, t_ps_list **head_b)
{
	t_ps_list	*min_cost_elt;

	while (ft_get_size(*head_a) > 3)
		pb(head_a, head_b);
	ft_sort_3_num(head_a);
	while (*head_b)
	{
		ft_set_cost(*head_b);
		ft_set_cost(*head_a);
		ft_set_target(*head_a, *head_b);
		min_cost_elt = ft_get_min_cost_elt(*head_b);
		ft_move_top_a_b(head_a, head_b, min_cost_elt);
		pa(head_b, head_a);
	}
	ft_set_cost(*head_a);
	ft_move_to_front(head_a, ft_get_min(*head_a), "A");
}
