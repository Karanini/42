

#include "list.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_elt;
	t_list	*new_elt2;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	content = (*f)(lst->content);
	if (!content)
		return (NULL);
	new_elt = ft_lstnew(content);
	if (!new_elt)
	{
		del(content);
		return (NULL);
	}
	while (lst->next)
	{
		lst = lst->next;
		content = (*f)(lst->content);
		if (!content)
		{
			ft_lstclear(&new_elt, del);
			return (NULL);
		}
		new_elt2 = ft_lstnew(content);
		if (!new_elt2)
		{
			del(content);
			ft_lstclear(&new_elt, del);
			return (NULL);
		}
		ft_lstadd_back(&new_elt, new_elt2);
	}
	return (new_elt);
}
