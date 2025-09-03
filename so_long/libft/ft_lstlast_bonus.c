/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:11:49 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/05/19 17:11:53 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*res;

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
