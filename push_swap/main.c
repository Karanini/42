/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:51:28 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/21 12:03:46 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char		**tab_str;
	size_t		total_size;
	t_ps_list	*head_stack_a;
	t_ps_list	*head_stack_b;

	if (argc == 1)
		return (1);
	tab_str = ft_parsing(argc, argv, &total_size);
	if (!tab_str)
		return (ft_putstr_fd("Error\n", 2), 1);
	head_stack_a = ft_init_stack(tab_str, total_size);
	if (!head_stack_a)
		return (ft_free_tab_str(tab_str), ft_putstr_fd("Error\n", 2), 1);
	head_stack_b = NULL;
	print_list(head_stack_a);
	for (size_t i = 0; i < total_size; i++)
	{
		ft_printf("tab_str elt num %d : %s\n", i, tab_str[i]);
	}
	ft_free_tab_str(tab_str);
	ft_lstclear(&head_stack_a);
	return (0);
	// ft_init_list(tab_str);
}
