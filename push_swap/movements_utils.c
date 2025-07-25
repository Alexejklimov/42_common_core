/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:07:41 by oklimov           #+#    #+#             */
/*   Updated: 2025/01/17 14:27:23 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_ra_rb(t_data *stack, t_stack *last, t_stack *head, char c)
{
	static t_stack	*tmp = NULL;

	if (c == 'a' && stack->stack_a)
	{
		head = stack->stack_a;
		last = ft_lstlaste(stack->stack_a);
		tmp = stack->stack_a;
		stack->stack_a = stack->stack_a->next;
		last->next = head;
		head->next = NULL;
	}
	if (c == 'b' && stack->stack_b)
	{
		head = stack->stack_b;
		last = ft_lstlaste(stack->stack_b);
		tmp = stack->stack_b;
		stack->stack_b = stack->stack_b->next;
		last->next = head;
		head->next = NULL;
	}
}

void	ft_rotate_rrb_rra(t_data *stack, t_stack *last, char c)
{
	static t_stack	*tmp = NULL;

	if (c == 'a' && stack->stack_a)
	{
		last = ft_lstlaste(stack->stack_a);
		tmp = stack->stack_a;
		while (tmp->next != last)
			tmp = tmp->next;
		tmp->next = NULL;
		last->next = stack->stack_a;
		stack->stack_a = last;
	}
	if (c == 'b' && stack->stack_b)
	{
		last = ft_lstlaste(stack->stack_b);
		tmp = stack->stack_b;
		while (tmp->next != last)
			tmp = tmp->next;
		tmp->next = NULL;
		last->next = stack->stack_b;
		stack->stack_b = last;
	}
}

void	ft_pushmin(t_data *stack)
{
	static t_stack	*small = NULL;
	static t_stack	*curr = NULL;
	int				index;

	curr = stack->stack_a;
	small = find_small_nb(stack);
	index = ft_find_nb_list_index(stack->stack_a, stack, small->number, 'o');
	while (stack->stack_a->number != small->number)
	{
		if (index <= stack->counter_a / 2)
			ft_ra_rb(stack, 'a');
		else
			ft_rra_rrb(stack, 'a');
	}
	ft_push_stack(stack, 'b');
}

void	ft_three_nb_algo_movement(t_data *stack, t_stack *small)
{
	if (stack->stack_a->number > stack->stack_a->next->number
		&& stack->stack_a->next->next->number == small->number)
	{
		ft_sa_sb(stack, 'a');
		ft_rra_rrb(stack, 'a');
	}
	if (stack->stack_a->number < stack->stack_a->next->next->number
		&& stack->stack_a->next->number == small->number)
		ft_sa_sb(stack, 'a');
}
