
#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *))
{
    // verify if this security is needed
    // if (!lst || !f)
    //     return ;
    while (lst)
    {
        (*f)(lst->content);
        lst=lst->next;
    }
}