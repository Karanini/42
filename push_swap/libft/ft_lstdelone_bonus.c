/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:04:05 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/05/19 17:04:05 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* ************************************************************************** *
This function does NOT test if !lst or !del.
* This security check is not mandatory to pass the tests, it's a choice
* depending on what we prefer to get in case of an error : nothing or segfault
* An other important parameter to consider : the code is slower when one
* implements many checks
* Also, this function does NOT modify the 'next' pointer of the node
* preceding the node to delete
*************************************************************************** */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
