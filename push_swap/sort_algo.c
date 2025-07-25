/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:09:51 by oklimov           #+#    #+#             */
/*   Updated: 2025/01/17 14:27:38 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_nb_algo(t_data *stack, int i)
{
	static t_stack	*small = NULL;
	static t_stack	*curr = NULL;

	i = 1;
	small = find_small_nb(stack);
	curr = stack->stack_a;
	while (curr != NULL)
	{
		if (i == 2 && curr->number == small->number
			&& stack->stack_a->number > stack->stack_a->next->next->number)
			ft_ra_rb(stack, 'a');
		if (i == 1 && curr->number == small->number)
		{
			ft_sa_sb(stack, 'a');
			ft_ra_rb(stack, 'a');
		}
		if (i == 3 && curr->number == small->number
			&& stack->stack_a->number < stack->stack_a->next->number)
			ft_rra_rrb(stack, 'a');
		curr = curr->next;
		i++;
	}
	ft_three_nb_algo_movement(stack, small);
}

void	ft_optimal_moves_finder(t_data *stack)
{
	t_stack	*curr_b;
	int		index_a;
	int		index_b;
	int		nbsup_b;
	int		tab[4];

	stack->move = ft_calloc(1, sizeof(t_cmove));
	if (!stack->move)
		ft_free_error_3(stack);
	curr_b = stack->stack_b;
	while (curr_b != NULL)
	{
		nbsup_b = ft_nb_superior_bound(curr_b, stack);
		index_a = ft_find_nb_list_index(stack->stack_a, stack, nbsup_b, 'o');
		index_b = ft_find_nb_list_index(stack->stack_b,
				stack, curr_b->number, 'o');
		tab[0] = index_a;
		tab[1] = ft_find_nb_list_index(stack->stack_a, stack, nbsup_b, 'a');
		tab[2] = index_b;
		tab[3] = ft_find_nb_list_index(stack->stack_b,
				stack, curr_b->number, 'r');
		ft_countdatamove(stack, tab);
		curr_b = curr_b->next;
	}
}

static void	ft_bestmove(t_data *stack)
{
	while (stack->move->booll[0] || stack->move->booll[1]
		|| stack->move->booll[2] || stack->move->booll[3])
	{
		if ((stack->move->booll[0] && stack->move->booll[2]))
			ft_best_is_rr_or_rrr(stack, 2, 0, 2);
		else if (stack->move->booll[0] || stack->move->booll[2])
			ft_best_is_ra_or_rb(stack);
		if ((stack->move->booll[1] && stack->move->booll[3]))
			ft_best_is_rr_or_rrr(stack, 1, 1, 3);
		else if ((stack->move->booll[1] && stack->move->tabmouv[1])
			|| (stack->move->booll[3] && stack->move->tabmouv[3]))
			ft_best_is_rra_or_rrb(stack);
	}
	ft_push_stack(stack, 'a');
}

static void	ft_sort(t_data *stack)
{
	t_stack	*smallnb;
	t_stack	*curr;
	int		i;

	smallnb = find_small_nb(stack);
	i = ft_find_nb_list_index(stack->stack_a, stack, smallnb->number, 'o');
	while (stack->stack_a->number != smallnb->number)
	{
		curr = stack->stack_a;
		if (i <= (stack->counter_a / 2))
			ft_ra_rb(stack, 'a');
		else
			ft_rra_rrb(stack, 'a');
	}
}

void	ft_big_nb_algo(t_data *stack)
{
	ft_sort(stack);
	while (stack->counter_b != 0)
	{
		ft_optimal_moves_finder(stack);
		ft_bestmove(stack);
		free(stack->move);
	}
	ft_sort(stack);
}
