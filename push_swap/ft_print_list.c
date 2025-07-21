/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:08:19 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/21 14:29:04 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Prints each node of the list. Only values at the moment*/
void	print_list_complete(t_ps_list *lst)
{
	t_ps_list	*print_node = lst;
	int	i;

	if (!print_node)
	{
		ft_printf("The list is empty");
		return ;
	}
	i = 1;
	while (print_node)
	{
		ft_printf("node num %p :\n   value : %d\n   index : %d\n   next node : %p\n",
				print_node, print_node->val, print_node->index, print_node->next);
		ft_printf("***********************\n");
		i++;
		print_node = print_node->next;
	}
}

void	print_list_val(t_ps_list *lst)
{
	t_ps_list	*print_node = lst;

	if (!print_node)
	{
		ft_printf("The list is empty");
		return ;
	}
	while (print_node)
	{
		if (print_node->next)
			ft_printf("%d -> ", print_node->val);
		else
			ft_printf("%d -> %p\n", print_node->val, print_node->next);
		print_node = print_node->next;
	}
}
