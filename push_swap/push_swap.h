/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:51:14 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/21 12:00:00 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_push_swap
{
	int					val;
	size_t				index;
	size_t				target;
	int					cost_a;
	int					cost_b;
	struct s_push_swap	*next;
}						t_ps_list;

t_ps_list				*ft_lstnew(int val);
void					ft_lstadd_front(t_ps_list **begin_lst, t_ps_list *new);
void					ft_lstadd_back(t_ps_list **lst, t_ps_list *new);
t_ps_list				*ft_lstlast(t_ps_list *lst);
void					print_list(t_ps_list *lst);
void					ra(t_ps_list **stack_a);
void					rb(t_ps_list **stack_b);
void					rr(t_ps_list **stack_a, t_ps_list **stack_b);
void					sa(t_ps_list **stack_a);
void					sb(t_ps_list **stack_b);
void					ss(t_ps_list **stack_a, t_ps_list **stack_b);
void					ft_lstclear(t_ps_list **lst);
void					pa(t_ps_list **stack_b, t_ps_list **stack_a);
void					pb(t_ps_list **stack_a, t_ps_list **stack_b);

char					**ft_parsing(int argc, char *argv[], size_t *total_size);
t_ps_list				*ft_init_stack(char *tab_str[], size_t total_size);

void					ft_free_tab_str(char **split);




// int ft_lstsize(t_list *lst);
// void ft_lstadd_back(t_list **lst, t_list *new);
// void ft_lstdelone(t_list *lst, void (*del)(void *));
// void ft_lstclear(t_list **lst, void (*del)(void *));
// void ft_lstiter(t_list *lst, void (*f)(void *));
// t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
