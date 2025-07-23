/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:31:21 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/22 13:44:15 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3_num(t_ps_list **head_a)
{
	t_ps_list	*elt;
	t_ps_list	*max;

	elt = *head_a;
	max = (*head_a)->next;
	while (elt)
	{
		if (elt->index > max->index)
			max = elt;
		elt = elt->next;
	}
	if (max == *head_a)
		ra(head_a);
	else if (max == (*head_a)->next)
		rra(head_a); // a coder
	if ((*head_a)->val > (*head_a)->next->val)
		sa(head_a);
}
