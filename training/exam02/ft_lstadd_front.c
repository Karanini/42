#include"list.h"


void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// Helper function to print the entire linked list
// static void print_list(t_list *lst)
// {
// 	t_list *current = lst;
// 	int i = 0;

// 	printf("Linked list contents:\n");
// 	while (current != NULL)
// 	{
// 		printf("Node %d: \"%s\" (address: %p, next: %p)\n",
// 			i, (char*)current->content, current, current->next);
// 		current = current->next;
// 		i++;
// 	}
// 	printf("--- End of list ---\n\n");
// }

// int main(void)
// {
// 	t_list *lst = ft_lstnew("yo");
// 	t_list *new = ft_lstnew("yoyo");

// 	printf("Before ft_lstadd_front:\n");
// 	printf("lst content: %s\n", (char*)lst->content);
// 	printf("new content: %s\n", (char*)new->content);

// 	ft_lstadd_front(&lst, new);

// 	printf("\nAfter ft_lstadd_front:\n");
// 	printf("First node content: %s\n", (char*)lst->content);
// 	printf("Second node content: %s\n", (char*)lst->next->content);

// 	print_list(lst); // Print the entire list after addition

// 	return (0);
// }
