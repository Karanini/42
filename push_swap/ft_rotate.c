/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:06:20 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/16 18:26:32 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

/**
 * @brief Rotates the elements of the given linked list upwards.
 *
 * Moves the first element of the list to the end, effectively rotating
 * the list so that the second element becomes the new head.
 *
 * @param begin Double pointer to the head of the t_ps_list linked list.
 */
static void	ft_rotate(t_ps_list **begin)
{
	t_ps_list	*elt;
	t_ps_list	*old_last;

	if (!begin || !*begin || !(*begin)->next)
		return ;
	elt = *begin;
	old_last = ft_lstlast(*begin);
	*begin = (*begin)->next;
	elt->next = NULL;
	old_last->next = elt;
}

void	ra(t_ps_list **stack_a)
{
	ft_rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_ps_list **stack_b)
{
	ft_rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_ps_list **stack_a, t_ps_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
