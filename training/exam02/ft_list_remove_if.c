

#include "ft_list.h"
#include <string.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;
	t_list	*previous;
	t_list	*temp;

	if (!begin_list || !*begin_list)
		return ;

	previous = NULL;
	current = *begin_list;
	while (current)
	{
		if ((*cmp)(current->data, data_ref) == 0)
		{
			if (previous)
				previous->next = current->next;
			else
				*begin_list = current->next;
			temp = current;
			current = current->next;
			free(temp);
		}
		else
		{
			previous = current;
			current = current->next;
		}
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
// 	ft_list_remove_if(&elt3, (char *)"0", &strcmp);
// 	print_list(elt3);
// 	return (0);
// }

// // variante 1 current et previous (ptr simple)
// void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
// {
//     t_list *current;
//     t_list *previous;

//     if (begin_list == NULL || *begin_list == NULL)
//         return;

//     current = *begin_list;
//     previous = NULL;

//     while (current != NULL)
//     {
//         if (cmp(current->data, data_ref) == 0)
//         {
//             if (previous == NULL)
//                 *begin_list = current->next;
//             else
//                 previous->next = current->next;

//             t_list *temp = current;
//             current = current->next;
//             free(temp);
//         }
//         else
//         {
//             previous = current;
//             current = current->next;
//         }
//     }
// }

