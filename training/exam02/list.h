


#ifndef LIST_H
#define LIST_H

#include<stdio.h>
#include<stdlib.h>

typedef struct	s_list
{
	void		*content;
	struct s_list	*next;
}			t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	print_list(t_list *lst);
void 	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());


#endif
