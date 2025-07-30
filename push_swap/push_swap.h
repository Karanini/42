/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:51:14 by bkaras-g          #+#    #+#             */
/*   Updated: 2025/07/30 14:51:25 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>

typedef struct s_push_swap
{
	int					val;
	int					index;
	struct s_push_swap	*target;
	int					cost;
	struct s_push_swap	*next;
}						t_ps_list;

t_ps_list				*ft_lstnew(int val);
void					ft_lstadd_front(t_ps_list **begin_lst, t_ps_list *new);
void					ft_lstadd_back(t_ps_list **lst, t_ps_list *new);
t_ps_list				*ft_lstlast(t_ps_list *lst);
void					ft_lstclear(t_ps_list **lst);

void					print_list_complete(t_ps_list *lst);
void					print_list_val(t_ps_list *lst);
void					print_2_stacks(t_ps_list *head_a, t_ps_list *head_b);

void					ra(t_ps_list **stack_a);
void					rb(t_ps_list **stack_b);
void					rr(t_ps_list **stack_a, t_ps_list **stack_b);
void					rra(t_ps_list **stack_a);
void					rrb(t_ps_list **stack_b);
void					rrr(t_ps_list **stack_a, t_ps_list **stack_b);
void					sa(t_ps_list **stack_a);
void					sb(t_ps_list **stack_b);
void					ss(t_ps_list **stack_a, t_ps_list **stack_b);
void					pa(t_ps_list **stack_b, t_ps_list **stack_a);
void					pb(t_ps_list **stack_a, t_ps_list **stack_b);

char					**ft_parsing(int argc, char *argv[],
							size_t *total_size);
t_ps_list				*ft_init_stack(char *tab_str[], size_t total_size);
void					ft_sort(t_ps_list **head_a, t_ps_list **head_b,
							size_t total_size);

t_ps_list				*ft_get_max(t_ps_list *list);
t_ps_list				*ft_get_min(t_ps_list *list);
size_t					ft_get_size(t_ps_list *list);
void					ft_set_target(t_ps_list *head_a, t_ps_list *head_b);
void					ft_set_cost(t_ps_list *list);
t_ps_list				*ft_get_min_cost_elt(t_ps_list *head_b);
int						ft_get_total_cost(int abs_elt_cost, int abs_target_cost);
void					ft_move_to_front(t_ps_list **head, t_ps_list *elt,
							char *stack);
void					ft_move_top_A_B(t_ps_list **head_a, t_ps_list **head_b,
							t_ps_list *elt);
int						ft_abs(int n);

void					ft_free_tab_str(char **split);

#endif
