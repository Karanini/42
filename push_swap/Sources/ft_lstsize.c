/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:15:30 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/16 12:48:47 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_ps_list *lst)
{
	int			i;
	t_ps_list	*next_elt;

	i = 0;
	next_elt = lst;
	while (next_elt != NULL)
	{
		next_elt = next_elt->next;
		i++;
	}
	return (i);
}
