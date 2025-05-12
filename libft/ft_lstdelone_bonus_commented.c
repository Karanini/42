#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
    // this security check is not mandatory to pass the tests
	// it's a choice depending on what we prefer to get in
	// case of an error : nothing or segfault
	// an other important parameter to consider : the code is
	// slower when we implement many checks
    // if (!lst || !del)
    //     return ;
    // (*del) and del are equivalent for the compiler
    // when del is a function pointer
    del(lst->content);
    free(lst);
}

//pourquoi est-ce qu'on ne supprime pas le ptr vers
// le prochain node ?
