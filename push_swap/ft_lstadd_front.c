/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:00:44 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/15 15:24:19 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Adds a new element at the beginning of a linked list.
 *
 * This function inserts the given 'new' node at the front of the list
 * pointed to by 'begin_lst'. After execution, 'new' becomes the first
 * element of the list.
 *
 * @param begin_lst Pointer to the pointer of the first element of the list.
 * @param new Pointer to the new node to be added to the front of the list.
 */
void	ft_lstadd_front(t_ps_list **begin_lst, t_ps_list *new)
{
	if (*begin_lst)
		new->next = *begin_lst;
	*begin_lst = new;
}
