/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:35:12 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/01 13:56:48 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Swaps the first two elements of the given linked list.
 *
 * @param begin Pointer to the pointer of the head of the list (t_ps_list).
 *              If the list has fewer than two elements, no action is taken.
 */
void	ft_swap(t_ps_list **begin)
{
	t_ps_list	*first;
	t_ps_list	*second;

	if (!begin || !*begin || !(*begin)->next)
		return ;
	first = *begin;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*begin = second;
}

void	sa(t_ps_list **stack_a)
{
	ft_swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_ps_list **stack_b)
{
	ft_swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_ps_list **stack_a, t_ps_list **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}
