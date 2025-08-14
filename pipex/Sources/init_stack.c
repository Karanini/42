/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:43:09 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/14 15:16:56 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	*ft_init_stack(char **argv, int nb_cmds)
{
	t_cmd	*begin;
	t_cmd	*elt;
	int		i;

	begin = NULL;
	elt = NULL;
	i = 0;
	while (i < nb_cmds)
	{
		elt = ft_lstnew(argv[i]);
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
	new_element->cmd = args[0];
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
