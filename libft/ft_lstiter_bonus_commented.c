
#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *))
{
    // this security check is not mandatory to pass the tests
	// it's a choice depending on what we prefer to get in
	// case of an error : nothing or segfault
	// an other important parameter to consider : the code is
	// slower when we implement many checks
    // if (!lst || !f)
    //     return ;
    while (lst)
    {
        (*f)(lst->content);
        lst=lst->next;
    }
}
