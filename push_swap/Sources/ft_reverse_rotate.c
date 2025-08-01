/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:43:38 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/01 13:43:52 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_ps_list **begin)
{
	t_ps_list	*new_last;
	t_ps_list	*old_last;

	if (!begin || !*begin || !(*begin)->next)
		return ;
	old_last = ft_lstlast(*begin);
	new_last = *begin;
	while (new_last->next != old_last)
		new_last = new_last->next;
	new_last->next = NULL;
	old_last->next = *begin;
	*begin = old_last;
}

/**
 * @brief Performs a reverse rotate operation on stack A.
 *
 * The reverse rotate operation shifts down all elements of stack A by one.
 * The last element becomes the first one.
 *
 * @param stack_a Double pointer to the head of stack A.
 */
void	rra(t_ps_list **stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

/**
 * @brief Performs a reverse rotate operation on stack B.
 *
 * Moves the last element of stack B to the top of the stack.
 *
 * @param stack_b Double pointer to the head of stack B.
 */
void	rrb(t_ps_list **stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

/**
 * @brief Performs a reverse rotate operation on both stack_a and stack_b.
 *
 * This function shifts down all elements of both stacks by one.
 * The last element of each stack becomes the first one.
 *
 * @param stack_a Pointer to the pointer of the first stack (stack_a).
 * @param stack_b Pointer to the pointer of the second stack (stack_b).
 */
void	rrr(t_ps_list **stack_a, t_ps_list **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
