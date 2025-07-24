/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:28:46 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/24 15:00:00 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
* to use only when list_size >= 2
*/
void	ft_set_target(t_ps_list *head_a, t_ps_list *head_b)
{
	t_ps_list	*target;
	t_ps_list	*current_a;

	while (head_b)
	{
		current_a = head_a;
		if (ft_get_max(head_a)->index > head_b->index) // if there are bigger numbers in A
		{
			target = ft_get_max(head_a);
			while (current_a)
			{
				// searching the nearest index in A above head_b->index
				if (current_a->index < target->index && current_a->index > head_b->index)
					target = current_a;
				current_a = current_a->next;
			}
		}
		else // head_b is the new max of A so target is the smallest number of A
			target = ft_get_min(head_a);
		head_b->target = target;
		head_b = head_b->next;
	}
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

t_ps_list	*ft_get_min_cost_elt(t_ps_list *head_b)
{
	t_ps_list	*min;
	t_ps_list	*elt;
	int			elt_cost;
	int			min_cost;

	if (!head_b->next)
		return (head_b);
	min = head_b;
	elt = head_b->next;
	elt_cost = 0;
	min_cost = 0;
	while (elt)
	{
		elt_cost = ft_abs(elt->cost) + ft_abs(elt->target->cost);
		min_cost = ft_abs(min->cost) + ft_abs(min->target->cost);
		if (elt_cost < min_cost)
			min = elt;
		elt = elt->next;
	}
	return (min);
}
