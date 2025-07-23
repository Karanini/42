/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:51:28 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/23 16:59:53 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	pb(&head_a, &head_b);
	pb(&head_a, &head_b);
	pb(&head_a, &head_b);
	print_2_stacks(head_a, head_b);
	t_ps_list *elt = head_b;
	while (elt)
	{
		ft_get_target(head_a, elt);
		elt = elt->next;
	}
	ft_printf("\nStack B with targets :\n");
	print_list_complete(head_b);
	ft_free_tab_str(tab_str);
	ft_lstclear(&head_a);
	return (0);
}
