/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:05:57 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/29 16:58:12 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/*
* mallocs inventory : (1) A t_cmd list, (2) **argv in the nodes, (3) *cmd in
the nodes if updated with absolute path, (4) a t_fdes node
*
* to do :
* exit codes
* memleaks on tests
* Protect the fdes closings : what happens if close(fd) fails ?
* Is everything stopped ? What is the exit status ?
*/
int	main(int argc, char *argv[], char *env[])
{
	t_fdes	*fdes;
	t_cmd	*head;
	int		main_ret;

	if (argc < 5)
		return (1);
	main_ret = 0;
	fdes = ft_check_files(argv, argc);
	if (!fdes)
		return (1);
	head = ft_init_cmd_list(argv, argc - 3);
	if (!head)
		return (ft_close_unused_fdes(fdes, NULL), free(fdes), 1);
	if (ft_check_path(head, env) == -1)
		return (ft_lstclear(&head), ft_close_unused_fdes(fdes, NULL),
			free(fdes), 1);
	if (ft_create_pipes(head) == -1)
		return (ft_close_unused_fdes(fdes, head), ft_lstclear(&head),
			free(fdes), 1);
	main_ret = ft_fork(fdes, head, env);
	if (main_ret == -1 || fdes->fd_outfile == -1)
		return (ft_lstclear(&head), free(fdes), 1);
	return (ft_lstclear(&head), free(fdes), main_ret);
}
