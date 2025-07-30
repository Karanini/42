
#include "push_swap.h"

/**
 * @brief Pushes the first element from one stack to another.
 *
 * This function removes the first element from the stack pointed to by begin_1
 * and inserts it at the beginning of the stack pointed to by begin_2.
 *
 * @param begin_1 Double pointer to the head of the source stack.
 * @param begin_2 Double pointer to the head of the destination stack.
 */
void	ft_push(t_ps_list **begin_1, t_ps_list **begin_2)
{
	t_ps_list	*elt;

	if (!begin_1 || !*begin_1 || !begin_2)
		return ;
	elt = (*begin_1)->next;
	(*begin_1)->next = *begin_2;
    *begin_2 = *begin_1;
    *begin_1 = elt;
}

void	pa(t_ps_list **stack_b, t_ps_list **stack_a)
{
	ft_push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_ps_list **stack_a, t_ps_list **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}



