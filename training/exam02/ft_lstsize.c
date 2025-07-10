
#include"list.h"
#include<stdio.h>

int	ft_lstsize(t_list *lst)
{
	int	len;
	t_list	*elt;

	len = 0;
	elt = lst;
	while(elt)
	{
		elt = elt->next;
		len++;
	}
	return(len);
}

/*int	main(void)
{
	t_list	*elt1 = ft_lstnew("1");
	printf("list size (1) : %d\n", ft_lstsize(elt1));
	t_list	*elt2 = ft_lstnew("32");
	ft_lstadd_front(&elt1, elt2);
	printf("list size (2) : %d\n", ft_lstsize(elt2));
	t_list	*elt3 = ft_lstnew("w32h");
	ft_lstadd_front(&elt2, elt3);
	printf("list size (3) : %d\n", ft_lstsize(elt3));
	return (0);
}
*/

