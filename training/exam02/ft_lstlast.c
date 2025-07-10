

#include"list.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*res;

	if (!lst)
		return (NULL);
	res = lst;
	while(res->next)
		res = res->next;
	return (res);
}

