
#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	content = f(lst->content);
	first = ft_lstnew(content);
	if (!first)
		return (del(content), NULL);
	lst = lst->next;
	while (lst)
	{
		content = f(lst->content);
		new = ft_lstnew(content);
		if (!new)
		{
			del(content);
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, new);	
		lst = lst->next;
	}
	return (first);
}

#include <stdio.h>
#include <string.h>

/*static void	*ft_strlen_void(void *content)
{
	size_t	*len;

	len = malloc(sizeof(size_t));
	if (!len)
		return (NULL);
	*len = strlen((char *)content);
	return ((void *)len);
}

int	main(void)
{
	t_list	*str_node;
	t_list	*strlen_node;

	str_node = ft_lstnew(ft_strdup("hello!"));
	strlen_node = ft_lstmap(str_node, &ft_strlen_void, &free);
	printf("strlen_node=%ld\n", *(size_t *)(strlen_node->content));
	ft_lstclear(&str_node, &free);
	ft_lstclear(&strlen_node, &free);
	return (0);
}*/
