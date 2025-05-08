#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	t_list	*res;
	
	if (!lst)
		res = NULL;
	while (lst->next)
	{
		res = lst->next;
		lst = lst->next;
	}
	return (res);
}
