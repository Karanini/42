/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:08:19 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/14 15:21:30 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*Prints each node of a t_cmd list, detailed mode : each variable of the node
* is printed.
* @param lst pointer to the first node of the list. */
void	ft_print_list_complete(t_cmd *lst)
{
	t_cmd	*print_node;
	int		i;

	print_node = lst;
	if (!print_node)
	{
		ft_printf("The list is empty");
		return ;
	}
	i = 0;
	while (print_node)
	{
		ft_printf("node num %p :\n   cmd : %s\n", print_node, print_node->cmd);
		while (print_node->argv[i])
		{
			ft_printf("   argv[%d] : %s   ", i, print_node->argv[i]);
			i++;
		}
		ft_printf("\n");
		ft_printf("   fd[0] : %d   fd[1] :   %d", print_node->pfd[0],
			print_node->pfd[1]);
		ft_printf("   fd_in : %d", print_node->fd_in);
		ft_printf("   fd_out : %d", print_node->fd_out);
		ft_printf("   next node : %p\n", print_node->next);
		ft_printf("***********************\n");
		print_node = print_node->next;
		i = 0;
	}
}

// void	print_list_val(t_cmd *lst)
// {
// 	t_cmd	*print_node;

// 	print_node = lst;
// 	if (!print_node)
// 	{
// 		ft_printf("The list is empty");
// 		return ;
// 	}
// 	while (print_node)
// 	{
// 		if (print_node->next)
// 			ft_printf("%d -> ", print_node->val);
// 		else
// 			ft_printf("%d -> %p\n", print_node->val, print_node->next);
// 		print_node = print_node->next;
// 	}
// }

// void	print_2_stacks(t_cmd *head_a, t_cmd *head_b)
// {
// 	t_cmd	*print_a;
// 	t_cmd	*print_b;

// 	print_a = head_a;
// 	print_b = head_b;
// 	ft_printf("\nA   B\n");
// 	while (print_a || print_b)
// 	{
// 		if (print_a)
// 		{
// 			ft_printf("%d   ", print_a->val);
// 			print_a = print_a->next;
// 		}
// 		else
// 			ft_printf("    ");
// 		if (print_b)
// 		{
// 			ft_printf("%d\n", print_b->val);
// 			print_b = print_b->next;
// 		}
// 		else
// 			ft_printf("  \n");
// 	}
// }
