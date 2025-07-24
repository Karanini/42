/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:28:46 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/24 11:56:31 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
* to use only when list_size >= 2
*/
void	ft_set_target(t_ps_list *head_a, t_ps_list *head_b)
{
	t_ps_list	*target;
	t_ps_list	*elt_a;
	t_ps_list	*elt_b;

	elt_a = head_a;
	elt_b = head_b;
	while (elt_b)
	{
		if (ft_get_max(head_a)->index > elt_b->index) // if there are bigger numbers in A
		{
			target = ft_get_max(head_a);
			while (elt_a)
			{
				// searching the nearest index in A above elt_b->index
				if (elt_a->index < target->index && elt_a->index > elt_b->index)
					target = elt_a;
				elt_a = elt_a->next;
			}
			elt_a = head_a;
		}
		else // elt_b is the new max of A so target is the smallest number of A (then
		// we just have to rotate the max to put it to the last position of A)
			target = ft_get_min(head_a);
		elt_b = elt_b->next;
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
