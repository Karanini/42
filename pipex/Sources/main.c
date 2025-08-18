/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:05:57 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/18 15:20:32 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
* mallocs inventory : (1) A t_cmd list, (2) **argv in the nodes, (3) *cmd in
the nodes if updated with absolute path, (4) a t_fdes node
*
* to do :
* ft_check_path : comment prendre en compte les binaires a executer dans
* le dossier courant ?
* maj parsing
* "filename: no such file or directory" : recuperer le filename avec argv
* modifier le ft_split pour prendre en compte ' '
*/
int	main(int argc, char *argv[], char *env[])
{
	t_fdes	*fdes;
	t_cmd	*head;
	t_cmd	*cmd;

	if (argc < 5)
		return (1);
	fdes = ft_check_files(argv, argc);
	if (!fdes)
		return (1);
	head = ft_init_cmd_list(argv, argc - 3);
	ft_print_list_complete(head);
	if (!head)
		return (free(fdes), 1);
	// we check if !head->cmd in case the ft_strdup in the ft_check_path fails
	cmd = head;
	while (cmd)
	{
		if (ft_check_path(cmd, env) == -1 || !cmd->cmd_name)
			return (ft_lstclear(&head), free(fdes), 1);
		cmd = cmd->next;
	}

	if (ft_create_pipes(head) == -1)
		return (ft_lstclear(&head), free(fdes), 1);
	// ft_printf("\nAfter creating pipes:\n");
	// ft_print_list_complete(head);
	if (ft_fork(fdes, head, env) == -1)
		return (ft_lstclear(&head), free(fdes), 1);
	return (ft_lstclear(&head), free(fdes), 0);
}
