/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:06:20 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/01 13:45:01 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Rotates the elements of the given linked list upwards.
 *
 * Moves the first element of the list to the end, effectively rotating
 * the list so that the second element becomes the new head.
 *
 * @param begin Double pointer to the head of the t_ps_list linked list.
 */
void	ft_rotate(t_ps_list **begin)
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

/**
 * @brief Rotates stack_a upwards by one position.
 *
 * The first element of stack_a becomes the last one.
 *
 * @param stack_a Double pointer to the head of the stack_a list.
 */
void	ra(t_ps_list **stack_a)
{
	ft_rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

/**
 * @brief Rotates stack_b upwards by one position.
 *
 * The first element of stack_b becomes the last one.
 *
 * @param stack_b Double pointer to the head of stack_b.
 */
void	rb(t_ps_list **stack_b)
{
	ft_rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

/**
 * @brief Rotates both stack_a and stack_b upwards by one position.
 *

* This function performs a simultaneous rotate operation on
	both stack_a and stack_b.
 * The first element of each stack becomes the last one.
 *
 * @param stack_a Double pointer to the head of stack A.
 * @param stack_b Double pointer to the head of stack B.
 */
void	rr(t_ps_list **stack_a, t_ps_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
