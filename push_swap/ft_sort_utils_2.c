/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:28:46 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/23 16:36:13 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_list	*ft_get_target(t_ps_list *head_a, t_ps_list *nbr)
{
	t_ps_list	*target;
	t_ps_list	*elt;

	target = head_a;
	elt = head_a->next;
	if (ft_get_max(head_a)->index > nbr->index)
	{
		while (elt)
		{
			if (elt->index < target->index && elt->index > nbr->index)
				target = elt;
			elt = elt->next;
		}
	}
	else
		target = ft_get_min(head_a);
	return (target);
}
