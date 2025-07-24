/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:31:21 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/24 11:56:10 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_3_num(t_ps_list **head_a);
static void	ft_sort_5_num(t_ps_list **head_a, t_ps_list **head_b,
				size_t total_size);
static void	ft_sort_yolo_num(t_ps_list **head_a, t_ps_list **head_b);

void	ft_sort(t_ps_list **head_a, t_ps_list **head_b, size_t total_size)
{
	if (total_size == 1)
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

static void	ft_sort_3_num(t_ps_list **head_a)
{
	t_ps_list	*elt;
	t_ps_list	*max;

	elt = *head_a;
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
		ft_move_to_front(head_a, min);
		pb(head_a, head_b);
		i++;
	}
	ft_sort_3_num(head_a);
	pa(head_b, head_a);
	if (total_size == 5)
		pa(head_b, head_a);
}

static void	ft_sort_yolo_num(t_ps_list **head_a, t_ps_list **head_b)
{
	t_ps_list	*min_cost_elt;

	while (ft_get_size(*head_a) > 3)
		pb(head_a, head_b);
	print_2_stacks(*head_a, *head_b);
	ft_sort_3_num(head_a);
	print_2_stacks(*head_a, *head_b);
	while (ft_get_size(*head_b) >= 2)
	{
		ft_set_cost(*head_b);
		ft_set_cost(*head_a);
		ft_set_target(*head_a, *head_b);
		min_cost_elt = ft_get_min_cost_elt(*head_b);
		ft_move_to_front(head_a, min_cost_elt->target);
		ft_move_to_front(head_b, min_cost_elt);
		pa(head_b, head_a);
		print_2_stacks(*head_a, *head_b);
	}
	pa(head_b, head_a);
	print_2_stacks(*head_a, *head_b);
	while ((*head_a)->index != 1)
		ra(head_a);
	print_2_stacks(*head_a, *head_b);
}
