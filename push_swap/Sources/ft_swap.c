/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:35:12 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/30 15:56:45 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_ps_list **begin)
{
		t_ps_list	*first;
		t_ps_list	*second;

		if (!begin || !*begin || !(*begin)->next)
			return ; //a voir si besoin de rajouter un exit avec erreur
		first = *begin;
		second = first->next;

		// Update pointers to swap first and second nodes
		first->next = second->next;
		second->next = first;

		// Update head pointer to point to what was previously the second node
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

