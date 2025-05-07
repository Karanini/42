
#include "libft.h"
#include <stdio.h>

int ft_lstsize(t_list *lst)
{
	int	i;
	t_list	*next_elt;

	i = 0;
	next_elt = lst;
	while (next_elt != NULL)
	{
		next_elt = next_elt->next;
		i++;
	}
	return (i);
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

	printf("list 1 size is %d (expected is 3)\n", ft_lstsize(lst1_elt1));
	
	lst2_elt1->next = NULL;

	printf("list 2 size is %d (expected is 1)\n", ft_lstsize(lst2_elt1));

	printf("list 3 size is %d (expected is 0)", ft_lstsize(lst3_elt1));
	
	free(lst1_elt1);
	free(lst1_elt2);
	free(lst1_elt3);
	free(lst2_elt1);
	return (0);
}*/
