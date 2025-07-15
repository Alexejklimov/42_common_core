/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:10:55 by oklimov           #+#    #+#             */
/*   Updated: 2025/01/17 13:15:22 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlaste(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstaddback(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (*lst)
	{
		last = ft_lstlaste(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

int	ft_find_nb_list_index(t_stack *stack, t_data *info, int nb, char c)
{
	int		index;
	t_stack	*curr;

	curr = stack;
	index = 0;
	while (curr != NULL)
	{
		if (curr->number == nb && c == 'o')
			break ;
		if (curr->number == nb && c == 'a')
			index = 0;
		if (curr->number == nb && c == 'r')
		{
			index = 0;
			if (curr->next == NULL
				&& info->counter_b == 1)
				return (index);
		}
		index++;
		curr = curr->next;
	}
	return (index);
}

void	ft_increase_decrease_counter(t_data *stack, char c)
{
	if (c == 'a')
	{
		if (stack->counter_b)
			stack->counter_b--;
		stack->counter_a++;
	}
	if (c == 'b')
	{
		if (stack->counter_a)
			stack->counter_a--;
		stack->counter_b++;
	}
}
