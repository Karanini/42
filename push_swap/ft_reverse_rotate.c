

#include "push_swap.h"

static void	ft_reverse_rotate(t_ps_list **begin)
{
	t_ps_list	*new_last;
	t_ps_list	*old_last;

	if (!begin || !*begin || !(*begin)-> next)
		return ;
	old_last = ft_lstlast(*begin);
	new_last = *begin;
	while (new_last->next != old_last)
		new_last = new_last->next;
	new_last->next = NULL;
	old_last->next = *begin;
	*begin = old_last;
}
void	rra(t_ps_list **stack_a)
{
		ft_reverse_rotate(stack_a);
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_ps_list **stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_ps_list **stack_a, t_ps_list **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}

