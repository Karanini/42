/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:43:09 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/08/06 11:19:38 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	*ft_init_stack(char **argv)
{
	t_cmd	*begin;
	t_cmd	*elt;
	int		i;

	begin = NULL;
	elt = NULL;
	i = 2;
	while (i < 4)
	{
		elt = ft_lstnew(argv[i]);
		if (!elt)
			return (ft_lstclear(&begin), NULL);
		ft_lstadd_front(&begin, elt);
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
	ft_printf("cmd with args : %s\n", cmd_with_args);
	args = ft_split(cmd_with_args, 32);
	int i = 0;
	while (args[i])
	{
		ft_printf("args[%d] : %s\n", i, args[i]);
		i++;
	}
	if (!args)
		return (NULL);
	new_element->cmd = args[0];
	new_element->argv = args;
	new_element->fd[0] = -1;
	new_element->fd[1] = -1;
	new_element->next = NULL;
	// ft_free_tab_str(args);
	return (new_element);
}

void	ft_lstadd_front(t_cmd **lst, t_cmd *new)
{
	if (*lst)
		new->next = *lst;
	*lst = new;
}

void	ft_lstclear(t_cmd **lst)
{
	t_cmd	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}
