/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:31:21 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/23 16:51:17 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_3_num(t_ps_list **head_a);
static void	ft_sort_5_num(t_ps_list **head_a, t_ps_list **head_b,
				size_t total_size);

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
