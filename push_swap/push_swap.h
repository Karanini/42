/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:51:14 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/17 17:43:27 by bkaras-g         ###   ########.fr       */
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

t_ps_list				*ft_lstnew(int val, size_t index, size_t target);
void					ft_lstadd_front(t_ps_list **begin_lst, t_ps_list *new);
t_ps_list				*ft_lstlast(t_ps_list *lst);
void					print_list(t_ps_list *lst);
void					ra(t_ps_list **stack_a);
void					rb(t_ps_list **stack_b);
void					rr(t_ps_list **stack_a, t_ps_list **stack_b);
void					sa(t_ps_list **stack_a);
void					sb(t_ps_list **stack_b);
void					ss(t_ps_list **stack_a, t_ps_list **stack_b);

// int ft_lstsize(t_list *lst);
// void ft_lstadd_back(t_list **lst, t_list *new);
// void ft_lstdelone(t_list *lst, void (*del)(void *));
// void ft_lstclear(t_list **lst, void (*del)(void *));
// void ft_lstiter(t_list *lst, void (*f)(void *));
// t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
