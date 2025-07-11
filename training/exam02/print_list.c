
#include "list.h"
#include <stdio.h>

void	print_list(t_list *lst)
{
	t_list	*print_node = lst;
	int	i;

	if (!print_node)
	{
		printf("The list is empty");
		return ;
	}
	i = 1;
	while (print_node)
	{
		printf("node num %d :\n   content : %s\n   address : %p\n   next node : %p\n",
				i, (char *)print_node->content, print_node, print_node->next);
		printf("***********************\n");
		i++;
		print_node = print_node->next;
	}
}
// int	main(void)
// {
// 	t_list	*elt1 = ft_lstnew("1");
// 	t_list	*elt2 = ft_lstnew("32");
// 	ft_lstadd_front(&elt1, elt2);
// 	t_list	*elt3 = ft_lstnew("w32h");
// 	ft_lstadd_front(&elt2, elt3);
// 	print_list(elt3);
// 	return (0);
// }
