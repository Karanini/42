/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:43:09 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/27 17:37:38 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
* initializes the commands list. Stores the command name and its arguments
* respectively in cmd->cmd_name and cmd->argv.
*
*/
t_cmd	*ft_init_cmd_list(char **argv, int nb_cmds)
{
	t_cmd	*begin;
	t_cmd	*elt;
	int		i;

	begin = NULL;
	elt = NULL;
	i = 0;
	while (i < nb_cmds)
	{
		if (!argv[i + 2][0] || ft_cmd_name_not_valid(argv[i + 2]))
		{
			ft_putstr_fd(argv[0], 2);
			ft_putstr_fd(": command not found\n", 2);
		}
		elt = ft_lstnew(argv[i + 2]);
		if (!elt)
			return (ft_lstclear(&begin), NULL);
		ft_lstadd_back(&begin, elt);
		i++;
	}
	return (begin);
}

t_cmd	*ft_lstnew(char	*cmd_with_args)
{
	t_cmd	*new_element;
	char	**args;

	new_element = malloc(sizeof(t_cmd));
	if (new_element == NULL)
		return (NULL);
	args = ft_split(cmd_with_args, 32);
	if (!args)
		return (NULL);
	new_element->cmd_name = args[0];
	new_element->argv = args;
	new_element->pid = -1;
	new_element->pfd[0] = -1;
	new_element->pfd[1] = -1;
	new_element->fd_in = -1;
	new_element->fd_out = -1;
	new_element->first = 0;
	new_element->next = NULL;
	// free_tab(args);
	return (new_element);
}

/* ************************************************************************** *
* No security check if !lst or !new
* If the list is empty, we add new as the first element of the list
* ************************************************************************** */
void	ft_lstadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*last_node;

	last_node = ft_lstlast(*lst);
	if (last_node == NULL)
		*lst = new;
	else
		last_node->next = new;
}

t_cmd	*ft_lstlast(t_cmd *lst)
{
	t_cmd	*res;

	if (lst == NULL)
		return (NULL);
	res = lst;
	while (res->next)
		res = res->next;
	return (res);
}

int	ft_lstsize(t_cmd *lst)
{
	int		i;
	t_cmd	*next_elt;

	i = 0;
	next_elt = lst;
	while (next_elt != NULL)
	{
		next_elt = next_elt->next;
		i++;
	}
	return (i);
}
