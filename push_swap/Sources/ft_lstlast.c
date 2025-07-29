/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:11:49 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/15 15:30:16 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Returns the last element of a linked list.
 *
 * @param lst Pointer to the first element of the list.
 * @return Pointer to the last element of the list, or NULL if the list is empty.
 */
t_ps_list	*ft_lstlast(t_ps_list *lst)
{
	t_ps_list	*res;

	if (lst == NULL)
		return (NULL);
	res = lst;
	while (res->next)
		res = res->next;
	return (res);
}

/*int	main(void)
{
	t_list	*lst1_elt1 = ft_lstnew(0);
	t_list	*lst1_elt2 = ft_lstnew(0);
	t_list	*lst1_elt3 = ft_lstnew(0);
	t_list	*lst2_elt1 = ft_lstnew(0);
	t_list	*lst3_elt1 = NULL;

	lst1_elt1->next = lst1_elt2;
	lst1_elt2->next = lst1_elt3;
	lst1_elt3->next = NULL;

	printf("list 1 last adress is %p (expected is %p)\n", ft_lstlast(lst1_elt1),
		lst1_elt3);

	lst2_elt1->next = NULL;

	printf("list 2 last adress is %p (expected is %p)\n", ft_lstlast(lst2_elt1),
		lst2_elt1);

	printf("list 3 last adress is %p (expected is (null))\n",
		ft_lstlast(lst3_elt1));

	free(lst1_elt1);
	free(lst1_elt2);
	free(lst1_elt3);
	free(lst2_elt1);
	return (0);
}*/
