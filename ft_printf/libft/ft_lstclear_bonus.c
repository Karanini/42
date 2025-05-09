
#include "libft.h"
#include <stdio.h>

// void ft_lstclear_old(t_list **lst, void (*del)(void *))
// {
//     t_list  *temp;

//     temp = ft_lstlast(*lst);
//     while (temp != *lst)
//     {
//         ft_lstdelone(temp, *del);
//         temp = ft_lstlast(*lst);
//     }
//     ft_lstdelone(temp, *del);
//     //free(lst);
//     *lst = NULL;
// }

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *temp;

    while (*lst)
    {
        temp = (*lst)->next;
        ft_lstdelone(*lst, del);
        *lst = temp;
    }
    // 2 prochaines lignes inutiles : *lst est deja NULL
    // free(*lst);
    // *lst = NULL;
}

// void ft_del(void *content)
// {
//     free(content);
// }

// int	main(void)
// {
// 	t_list	*lst1_elt1 = ft_lstnew(0);	
// 	t_list	*lst1_elt2 = ft_lstnew(0);	
// 	t_list	*lst1_elt3 = ft_lstnew(0);	
// 	// t_list	*lst2_elt1 = ft_lstnew(0);
// 	// t_list	*lst3_elt1 = NULL;

// 	lst1_elt1->next = lst1_elt2;
// 	lst1_elt2->next = lst1_elt3;
// 	lst1_elt3->next = NULL;

//     printf("List 1 initialisation\n");
//     printf("lst1_elt1 adress is %p\n", lst1_elt1);
//     printf("lst1_elt2 adress is %p\n", lst1_elt2);
//     printf("lst1_elt3 adress is %p\n", lst1_elt3);
//     printf("list 1 size is %d (expected is 3)\n", ft_lstsize(lst1_elt1));

//     lst1_elt1->next = NULL;
//     ft_lstclear(&lst1_elt2, &ft_del);

//     printf("List 1 cleared from lst1_elt2\n");
//     printf("lst1_elt1 adress is %p\n", lst1_elt1);
//     printf("lst1_elt2 adress is %p\n", lst1_elt2);
//     printf("lst1_elt3 adress is %p\n", lst1_elt3);
// 	printf("list 1 size is %d (expected is 1)\n", ft_lstsize(lst1_elt1));
	
// 	// lst2_elt1->next = NULL;

// 	// printf("list 2 size is %d (expected is 1)\n", ft_lstsize(lst2_elt1));

// 	// printf("list 3 size is %d (expected is 0)", ft_lstsize(lst3_elt1));
	
// 	free(lst1_elt1);
// 	// free(lst2_elt1);
// 	return (0);
// }