
#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *old_last;

    old_last = ft_lstlast(*lst);
    // if old_last is NULL, we add new as the first
    // element of the list
    if (old_last == NULL)
    {
        *lst = new;
        new->next = NULL;
        return ;
    }
    old_last->next = new;
    new->next = NULL;
}