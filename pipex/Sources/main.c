/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:05:57 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/06 18:25:07 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
* mallocs inventory : (1) Two stack nodes, (2) **argv in the nodes, (3) *cmd in
the nodes if updated with absolute path
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
		return (1);
	// we check if !head->cmd in case the ft_strdup in the ft_check_path fails
	if (ft_check_path(&(head->cmd), env) == -1 || !head->cmd
		|| ft_check_path(&(head->next->cmd), env) == -1 || !head->next->cmd)
		return (ft_lstclear(&head), 1);
	ft_print_list_complete(head);
	// ft_putstr_fd("on arrive ici ?\n", 1);
	if (ft_tunelling(fd_infile, fd_outfile, head) == -1)
	{
		ft_putstr_fd("on arrive ici tunelling == -1\n", 1);
		return (ft_lstclear(&head), 1);
	}
	ft_lstclear(&head);
	ft_putstr_fd("on arrive ici ?\n", 1);
	return (0);
}
