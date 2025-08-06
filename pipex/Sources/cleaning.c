/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:17:10 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/06 15:22:31 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
* @brief frees all the nodes of a t_cmd list with 2 steps : (1) Frees the
* allocated variables in a node, (2) then frees the node.
*
* If the cmd variable has been updated with the absolute path with ft_check_path,
* we free also cmd. If not, it's enough to free argv since argv[0] == cmd.
*/
void	ft_lstclear(t_cmd **lst)
{
	t_cmd	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		if (ft_strcmp((*lst)->argv[0], (*lst)->cmd))
			free((*lst)->cmd);
		free_tab((*lst)->argv);
		free(*lst);
		*lst = temp;
	}
}
