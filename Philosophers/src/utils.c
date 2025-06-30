/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:44:58 by oklimov           #+#    #+#             */
/*   Updated: 2025/06/30 12:56:23 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

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

int	ft_strncmp(const char *s1, const char *s2, size_t n)

{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++ ;
	}
	if (i < n)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
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

void	print_grave(int philo_num, t_data *data)
{
	time_t	now;

	now = timestamp() - data->start_time;
	printf("       _______\n");
	printf("      /       \\\n");
	printf("     /         \\\n");
	printf("    |   R.I.P   |\n");
	printf("    |           |\n");
	printf("    |    #%02d    |\n", philo_num + 1);
	printf("    |  0 - %ld |\n", now);
	printf("    |___________|\n");
	printf("     |         |\n");
	printf("  ^^^^  ^^^  ^^^^^^\n");
	printf(" ^     ^^^^     ^^^\n");
	printf("  ^^^^     ^^^  ^^^\n");
}
