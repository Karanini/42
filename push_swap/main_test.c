
#include "push_swap.h"

int		main(void)
{
	t_ps_list	*elt1 = ft_lstnew(32, 0, 0);
	t_ps_list	*elt2 = ft_lstnew(28, 0, 0);
	t_ps_list	*elt3 = ft_lstnew(1, 0, 0);
	t_ps_list	**begin_1 = &elt1;
	ft_lstadd_front(begin_1, elt2);
	ft_lstadd_front(begin_1, elt3);

	// t_ps_list	*node1 = NULL;
	t_ps_list	*node1 = ft_lstnew(9, 0, 0);
	t_ps_list	**begin_2 = &node1;

	ft_printf("Before operation stack 1 : \n\n");
	print_list(*begin_1);
	ft_printf("Before operation stack 2 : \n\n");
	print_list(*begin_2);

	ft_push(begin_1, begin_2);
	ft_push(begin_1, begin_2);
	ft_push(begin_1, begin_2);
	ft_push(begin_1, begin_2);

	ft_printf("After operation stack 1 : \n\n");
	print_list(*begin_1);
	ft_printf("After operation stack 2 : \n\n");
	print_list(*begin_2);
	return (0);
}
// ***********main test for swap**********

// int		main(void)
// {
// 	t_ps_list	*elt1 = ft_lstnew(32, 0, 0);
// 	t_ps_list	*elt2 = ft_lstnew(23, 0, 0);
// 	t_ps_list	*elt3 = ft_lstnew(5, 0, 0);
// 	t_ps_list	**begin_lst = &elt1;
// 	ft_lstadd_front(begin_lst, elt2);
// 	ft_lstadd_front(begin_lst, elt3);
// 	print_list(*begin_lst);
// 	ft_swap(begin_lst);
// 	print_list(*begin_lst);

// 	// Free all nodes in the list
// 	t_ps_list *current = *begin_lst;
// 	t_ps_list *next;
// 	while (current) {
// 		next = current->next;
// 		free(current);
// 		current = next;
// 	}
// 	return (0);
// }
