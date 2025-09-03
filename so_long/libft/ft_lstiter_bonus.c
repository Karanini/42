/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:10:45 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/05/19 17:10:45 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* ************************************************************************** *
This function does NOT test if !lst or !f.
* This security check is not mandatory to pass the tests, it's a choice
* depending on what we prefer to get in case of an error : nothing or segfault
* An other important parameter to consider : the code is slower when one
* implements many checks
*************************************************************************** */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
