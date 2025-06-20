/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:44:58 by oklimov           #+#    #+#             */
/*   Updated: 2025/06/20 17:12:59 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	acc;
	int	sign;

	i = 0;
	acc = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++ ;
	if (nptr[i] == '-')
	{
		sign = -sign;
		i++ ;
	}
	else if (nptr[i] == '+')
		i++ ;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		acc = acc * 10 + (nptr[i] - 48);
		i++ ;
	}
	return (acc * sign);
}

int	ft_isdigit(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] >= '0' && c[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_arguments(int ac, char **av)
{
	int	i;

	if (ac == 5 || ac == 6)
	{
		i = 1;
		while (i < ac)
		{
			if (ft_atoi(av[i]) > 0 && ft_isdigit(av[i]))
				i++;
			else
				return (printf("%s - Bad argument. \n", av[i]), 0);
		}
		return (1);
	}
	else
		printf("number of arguments is incorrect\n");
	return (0);
}



t_data	*initton(void)
{
	static t_data	data;

	return (&data);
}

t_time	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((t_time)(tv.tv_sec * 1000LL + tv.tv_usec / 1000));
}
