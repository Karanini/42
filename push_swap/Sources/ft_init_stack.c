/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:45:24 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/01 13:43:17 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static long long	ft_atol(const char *nptr);
static void			ft_init_index(t_ps_list *begin, size_t total_size);
static int			ft_duplicate_checker(t_ps_list *head, int nbr);

/**
 * Initializes a stack (linked list) for the push_swap project, while checking
 * if the numbers are in the `INT_MIN` / `INT_MAX` range, and checks for
 * duplicates
 *
 * @param tab_str      An array of strings, each representing an integer value
 *  to be added to the stack, in the following format : "x" or "-x" or "+x"
 * @param total_size   The total number of elements in the tab_str array.

 * @return             A pointer to the head of the initialized stack
  (t_ps_list), or NULL on failure (malloc failure or numbers above
  `INT_MIN` / `INT_MAX` range detected, or duplicates detected)
 */
t_ps_list	*ft_init_stack(char *tab_str[], size_t total_size)
{
	size_t		i;
	long long	nbr;
	t_ps_list	*new;
	t_ps_list	*begin;

	i = 0;
	begin = NULL;
	new = NULL;
	while (i < total_size)
	{
		nbr = ft_atol(tab_str[i]);
		if (nbr < INT_MIN || nbr > INT_MAX || ft_duplicate_checker(begin,
				(int)nbr))
			return (ft_free_tab_str(tab_str), ft_lstclear(&begin), NULL);
		new = ft_lstnew((int)nbr);
		if (!new)
			return (ft_free_tab_str(tab_str), ft_lstclear(&begin), NULL);
		ft_lstadd_back(&begin, new);
		i++;
	}
	if (total_size != 1)
		ft_init_index(begin, total_size);
	return (begin);
}

/*****************************************************************************
 *			/!\\/!\\/!\\ Modified version for push_swap /!\\/!\\/!\\
 *
 * @brief ft_atol converts ASCII to long long.
 *
 * Mods for push_swap :
 *
 * No whitespace check (deleted with the ft_split before)
 *
 * Parsing has already guaranteed that there are only digits,
 * possibly with only one '+' or '-' sign before the number.
 *
 * This function also checks if the number to convert is in the INT_MIN
 *	/ INT_MAX
 * range after each iteration
 * ***************************************************************************/
static long long	ft_atol(const char *nptr)
{
	size_t		i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			sign = -1;
	}
	while (nptr[i])
	{
		res *= 10;
		res += nptr[i] - '0';
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && res
				* sign < INT_MIN))
			return (res * sign);
		i++;
	}
	return (res * sign);
}

/**
 * Initializes the index values for each element in the stack.
 *
 * @param begin Pointer to the beginning of the stack (linked list).
 * @param total_size The total number of elements in the stack.
 *
 * This function assigns an index to each node in the stack, which can be used
 * for sorting or tracking the position of elements. The indexing starts from 0
 * and continues up to total_size - 1.
 */
static void	ft_init_index(t_ps_list *begin, size_t total_size)
{
	size_t		nb_sorted;
	t_ps_list	*smallest;
	t_ps_list	*elt;

	nb_sorted = 0;
	elt = begin;
	smallest = begin->next;
	while (nb_sorted < total_size - 1)
	{
		while (elt)
		{
			if (elt->index == -1 && elt->val < smallest->val)
				smallest = elt;
			elt = elt->next;
		}
		smallest->index = ++nb_sorted;
		elt = begin;
		while (elt->index != -1)
			elt = elt->next;
		smallest = begin->next;
		while (smallest->index != -1 && elt->val != smallest->val
			&& nb_sorted != total_size - 1)
			smallest = smallest->next;
	}
	elt->index = ++nb_sorted;
}

/**
 * Checks if the given number already exists in the stack.
 *
 * @param head Pointer to the head of the stack (linked list of t_ps_list).
 * @param nbr  The number to check for duplication in the stack.
 * @return     1 if the number is a duplicate, 0 otherwise.
 */
static int	ft_duplicate_checker(t_ps_list *head, int nbr)
{
	if (!head)
		return (0);
	while (head)
	{
		if (head->val == nbr)
			return (1);
		head = head->next;
	}
	return (0);
}
