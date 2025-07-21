/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:45:24 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/21 12:06:53 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	ft_atol(const char *nptr);

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
		if (nbr < INT_MIN || nbr > INT_MAX)
			return (ft_lstclear(&begin), NULL);
		new = ft_lstnew((int)nbr);
		if (!new)
			return (ft_lstclear(&begin), NULL);
		ft_lstadd_back(&begin, new);
		i++;
	}
	return (begin);
}

/*
* @brief ft_atol converts ASCII to long long. Function adapted to push_swap :
* no whitespace check, no '+' sign check (both deleted with the parsing before)
* Parsing also has already guaranteed that there are only digits.
* This function also checks if the number to convert is in the INT_MIN / INT_MAX
* range after each iteration
*/
static long long	ft_atol(const char *nptr)
{
	size_t	i;
	int		sign;
	long long		res;

	i = 0;
	sign = 1;
	res = 0;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i])
	{
		res *= 10;
		res += nptr[i] - '0';
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && res > INT_MAX - 1))
			return (res * sign);
		i++;
	}
	return (res * sign);
}


