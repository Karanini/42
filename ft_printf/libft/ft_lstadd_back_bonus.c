
#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *last_node;

    // verify if this security check is necessary
    // if (!lst || !new)
    //     return ;
    last_node = ft_lstlast(*lst);
    // if last_node is NULL, we add new as the first
    // element of the list
    if (last_node == NULL)
        *lst = new;
    else
        last_node->next = new;
}