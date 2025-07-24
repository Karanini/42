/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:51:28 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/24 16:03:12 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// a traiter : listes déjà triées
int	main(int argc, char *argv[])
{
	char		**tab_str;
	size_t		total_size;
	t_ps_list	*head_a;
	t_ps_list	*head_b;

	if (argc == 1)
		return (1);
	tab_str = ft_parsing(argc, argv, &total_size);
	if (!tab_str)
		return (ft_putstr_fd("Error\n", 2), 1);
	head_a = ft_init_stack(tab_str, total_size);
	if (!head_a)
		return (ft_free_tab_str(tab_str), ft_putstr_fd("Error\n", 2), 1);
	head_b = NULL;
	// print_2_stacks(head_a, head_b);
	// pb(&head_a, &head_b);
	// pb(&head_a, &head_b);
	// pb(&head_a, &head_b);
	// pb(&head_a, &head_b);
	// pb(&head_a, &head_b);
	// print_2_stacks(head_a, head_b);
	// // ft_printf("\nStack A :\n");
	// // print_list_complete(head_a);
	// ft_set_target(head_a, head_b);
	// ft_printf("\nStack B with targets :\n");
	// print_list_complete(head_b);
	ft_sort(&head_a, &head_b, total_size);
	ft_free_tab_str(tab_str);
	ft_lstclear(&head_a);
	return (0);
}


