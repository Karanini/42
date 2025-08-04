/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:56:59 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/05/19 16:56:59 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* ************************************************************************** *
* No security check if !lst or !new
* If the list is empty, we add new as the first element of the list
* ************************************************************************** */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	last_node = ft_lstlast(*lst);
	if (last_node == NULL)
		*lst = new;
	else
		last_node->next = new;
}
