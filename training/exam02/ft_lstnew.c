

#include"list.h"
#include<stdlib.h>
#include<stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

// int	main(int ac, char *av[])
// {
// 	(void)ac;
// 	t_list *element = ft_lstnew(av[1]);
// 	printf("%s\n", (char *)element->content);
// 	printf("%p\n", element->next);
// 	return (0);
// }
