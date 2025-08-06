/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:05:57 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/06 14:55:23 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
* mallocs inventory : (1) Two stack nodes, (2) **argv in the nodes, (3) *cmd in
the nodes
*/
int	main(int argc, char *argv[], char *env[])
{
	int		fd_outfile;
	int		fd_infile;
	t_cmd	*head;

	if (argc != 5)
		return (1);
	ft_check_files(argv, &fd_infile, &fd_outfile);
	head = ft_init_stack(argv);
	if (!head)
		exit(EXIT_FAILURE);
	// we check if !head->cmd in case the ft_strdup in the ft_check_path fails
	if (ft_check_path(&(head->cmd), env) == -1 || !head->cmd
		|| ft_check_path(&(head->next->cmd), env) == -1 || !head->next->cmd)
		exit(EXIT_FAILURE);
	// ft_putstr_fd("on arrive ici ?\n", 1);
	ft_print_list_complete(head);
	ft_tunelling(fd_infile, fd_outfile, argv);
	ft_lstclear(&head);
	return (0);
}
