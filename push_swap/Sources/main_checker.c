/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:50:15 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/30 17:02:44 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_cmd_in_set(char *cmd);
static int	ft_listen_input(t_ps_list **head_a, t_ps_list **head_b);
static int	ft_do_cmd(char *cmd, t_ps_list **head_a, t_ps_list **head_b);

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
		return (ft_putstr_fd("Error\n", 2), 1);
	ft_free_tab_str(tab_str);
	head_b = NULL;
	if (!ft_listen_input(&head_a, &head_b))
		return (ft_lstclear(&head_a), ft_lstclear(&head_b),
			ft_putstr_fd("Error\n", 2), 1);
	ft_lstclear(&head_a);
	ft_lstclear(&head_b);
	return (0);
}

static int	ft_listen_input(t_ps_list **head_a, t_ps_list **head_b)
{
	char	*input;
	char	*cmd;

	input = get_next_line(0);
	if (!input)
		return (0);
	while (input)
	{
		cmd = ft_strtrim(input, "\n");
		if (!cmd)
			return (0);
		free(input);
		if (!ft_cmd_in_set(cmd))
		{
			ft_printf("%s is a wrong cmd\n", cmd);
			return (0);
		}
		ft_do_cmd(cmd, head_a, head_b);
		free(cmd);
		input = get_next_line(0);
	}
	if (ft_is_sorted(*head_a) && !*head_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (free(input), 1);
}

static int	ft_cmd_in_set(char *cmd)
{
	char	*cmd_set[12];
	int		i;

	i = 0;
	cmd_set[0] = "sa";
	cmd_set[1] = "sb";
	cmd_set[2] = "ss";
	cmd_set[3] = "pa";
	cmd_set[4] = "pb";
	cmd_set[5] = "ra";
	cmd_set[6] = "rb";
	cmd_set[7] = "rr";
	cmd_set[8] = "rra";
	cmd_set[9] = "rrb";
	cmd_set[10] = "rrr";
	cmd_set[11] = NULL;
	while (cmd_set[i])
	{
		if (ft_strcmp(cmd, cmd_set[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_do_cmd(char *cmd, t_ps_list **head_a, t_ps_list **head_b)
{
	if (!ft_strcmp(cmd, "ra"))
		return (ft_rotate(head_a), 1);
	else if (!ft_strcmp(cmd, "rb"))
		return (ft_rotate(head_b), 1);
	else if (!ft_strcmp(cmd, "rr"))
		return (ft_rotate(head_a), ft_rotate(head_b), 1);
	else if (!ft_strcmp(cmd, "rra"))
		return (ft_reverse_rotate(head_a), 1);
	else if (!ft_strcmp(cmd, "rrb"))
		return (ft_reverse_rotate(head_b), 1);
	else if (!ft_strcmp(cmd, "rrr"))
		return (ft_reverse_rotate(head_a), ft_reverse_rotate(head_b), 1);
	else if (!ft_strcmp(cmd, "sa"))
		return (ft_swap(head_a), 1);
	else if (!ft_strcmp(cmd, "sb"))
		return (ft_swap(head_b), 1);
	else if (!ft_strcmp(cmd, "ss"))
		return (ft_swap(head_a), ft_swap(head_b), 1);
	else if (!ft_strcmp(cmd, "pa"))
		return (ft_push(head_b, head_a), 1);
	else if (!ft_strcmp(cmd, "pb"))
		return (ft_push(head_a, head_b), 1);
	return (0);
}
