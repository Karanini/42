/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:28:46 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/01 13:55:30 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * to use only when list_size >= 2
 */
/**
 * Sets the target node for each element in stack B based on the current
 * state of stack A.
 *
 * This function iterates through the elements of stack B and determines
 * the appropriate target node in stack A for each element.
 * The target node is the number in stack A above which the number from stack B
 * should be inserted to get sorted order.
 *
 * @param head_a Pointer to the head of stack A (t_ps_list).
 * @param head_b Pointer to the head of stack B (t_ps_list).
 */
void	ft_set_target(t_ps_list *head_a, t_ps_list *head_b)
{
	t_ps_list	*target;
	t_ps_list	*current_a;

	while (head_b)
	{
		current_a = head_a;
		if (ft_get_max(head_a)->index > head_b->index)
		{
			target = ft_get_max(head_a);
			while (current_a)
			{
				if (current_a->index < target->index
					&& current_a->index > head_b->index)
					target = current_a;
				current_a = current_a->next;
			}
		}
		else
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

/*
 * @brief returns the cheapest number to push from B to A : the number that
 * needs the least amount of operations to get to the top of B. takes into
 * account the cost of moving number's target on top of A. Takes into account
 * simultaneous rotations (rr and rrr)
 */
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
		elt_cost = ft_get_total_cost(elt->cost, elt->target->cost);
		min_cost = ft_get_total_cost(min->cost, min->target->cost);
		if (elt_cost < min_cost)
			min = elt;
		elt = elt->next;
	}
	return (min);
}

/*
 * @brief calculates total cost of pushing a number and it's target respectively
 * on top of B and A. Takes into account if there are simultaneous rotations
 * to do (rr or rrr)
 */
int	ft_get_total_cost(int elt_cost, int target_cost)
{
	int	total_cost;

	total_cost = 0;
	while (elt_cost > 0 && target_cost > 0)
	{
		total_cost++;
		elt_cost--;
		target_cost--;
	}
	while (elt_cost < 0 && target_cost < 0)
	{
		total_cost++;
		elt_cost++;
		target_cost++;
	}
	total_cost += ft_abs(elt_cost) + ft_abs(target_cost);
	return (total_cost);
}

/*
 * @brief moves the node elt to the top of B and elt->target to the top of A
 * performs simultaneous rotations when necessary (rr or rrr)
 */
void	ft_move_top_a_b(t_ps_list **head_a, t_ps_list **head_b, t_ps_list *elt)
{
	while (elt->cost > 0 && elt->target->cost > 0)
	{
		rr(head_a, head_b);
		elt->cost--;
		elt->target->cost--;
	}
	while (elt->cost < 0 && elt->target->cost < 0)
	{
		rrr(head_a, head_b);
		elt->cost++;
		elt->target->cost++;
	}
	if (elt->target->cost != 0)
		ft_move_to_front(head_a, elt->target, "A");
	if (elt->cost != 0)
		ft_move_to_front(head_b, elt, "B");
}
