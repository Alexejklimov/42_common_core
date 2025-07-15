/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:10:20 by oklimov           #+#    #+#             */
/*   Updated: 2025/01/20 14:42:52 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi2(const char *nptr, t_data *stack, char **temp)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while ((*nptr >= 7 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr && (*nptr >= '0' && *nptr <= '9'))
	{
		result = result * 10 + *nptr - '0';
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			ft_free_error(stack, temp);
		nptr++;
	}
	if (*nptr)
		ft_free_error(stack, temp);
	return (result * sign);
}

void	ft_error(int nb)
{
	if (nb == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (nb == 1)
	{
		ft_putstr_fd("Memory Allocation Failed\n", 2);
		exit(1);
	}
}

t_stack	*ft_addstack(int nb, t_data *stack, char **temp)
{
	t_stack	*ptr;

	ptr = malloc(sizeof(t_stack));
	if (!ptr)
	{
		ft_free(stack->stack_a);
		ft_free_split(temp);
		free(stack);
		ft_error(1);
	}
	ptr->number = nb;
	ptr->next = NULL;
	return (ptr);
}

t_stack	*find_small_nb(t_data *stack)
{
	static t_stack	*curr = NULL;
	static t_stack	*little = NULL;
	int				small;

	curr = stack->stack_a;
	little = curr;
	small = curr -> number;
	while (curr != NULL)
	{
		if (curr->next != NULL)
		{
			if (small > curr->next->number)
			{
				small = curr->next->number;
				little = curr->next;
			}
		}
		curr = curr->next;
	}
	return (little);
}
