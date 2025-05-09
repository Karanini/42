#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
    // verifiy if we need this security check
    // if (!lst || !del)
    //     return ;
    // (*del) and del are equivalent for the compiler 
    // when del is a function pointer
    del(lst->content);
    free(lst);
}

//pourquoi est-ce qu'on ne supprime pas le ptr vers 
// le prochain node ?