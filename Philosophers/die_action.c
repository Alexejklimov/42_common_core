/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:04:51 by oklimov           #+#    #+#             */
/*   Updated: 2025/06/27 16:58:00 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// static void	print_grave(int philo_num, t_data *data)
// {
// 	time_t	now;

// 	now = timestamp() - data->start_time;
// 	printf("       _______\n");
// 	printf("      /       \\\n");
// 	printf("     /         \\\n");
// 	printf("    |   R.I.P   |\n");
// 	printf("    |           |\n");
// 	printf("    |    #%02d    |\n", philo_num + 1);
// 	printf("    |  0 - %ld  |\n", now);
// 	printf("    |___________|\n");
// 	printf("     |         |\n");
// 	printf("  ^^^^  ^^^  ^^^^^^\n");
// 	printf(" ^     ^^^^     ^^^\n");
// 	printf("  ^^^^     ^^^  ^^^\n");
// }

int	is_philo_died(t_philo *philo)
{
	t_data		*data;
	int			i;

	data = initton();
	while (!data->die_flag)
	{
		i = -1;
		while (data->philo_nb > ++i)
		{
			pthread_mutex_lock(&philo[i].lock);
			if (timestamp() - philo[i].last_eat
				>= data->time_to_die)
				return (pthread_mutex_unlock(&philo[i].lock), dead_unlock(philo, i), /*print_grave(i, data),*/ 0);
			pthread_mutex_unlock(&philo[i].lock);
			if (check_eat_count(philo) == 1)
			{
				pthread_mutex_lock(&data->dead_mutex);
				data->die_flag = 1;
				pthread_mutex_unlock(&data->dead_mutex);
			}
		}
		usleep(100);
	}
	return (0);
}

int	check_eat_count(t_philo *philo)
{
	t_data		*data;
	int			i;
	int			count;

	data = initton();
	i = -1;
	count = 0;
	while (++i < data->philo_nb)
	{
		pthread_mutex_lock(&philo[i].lock);
		if (philo[i].eat_times_count == 0)
		{
			pthread_mutex_lock(&data->locker);
			count++;
			pthread_mutex_unlock(&data->locker);
		}
		pthread_mutex_unlock(&philo[i].lock);
	}
	if (count == data->philo_nb)
		return (1);
	return (0);
}

void	dead_unlock(t_philo *philo, int i)
{
	t_data		*data;

	data = initton();
	pthread_mutex_unlock(&philo[i].lock);
	pthread_mutex_lock(&data->dead_mutex);
	data->die_flag = 1;
	pthread_mutex_unlock(&data->dead_mutex);
	print_action(&philo[i], "died\n");
}

void	ft_destroy_mutex(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_nb)
	{
		pthread_mutex_destroy(&philo[i].count_lock);
		pthread_mutex_destroy(&philo[i].left_fork);
		pthread_mutex_destroy(&philo[i].lock);
	}
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->locker);
	pthread_mutex_destroy(&data->dead_mutex);
}

int	check_arguments(int ac, char **av)
{
	int	i;

	if (ac == 5 || ac == 6)
	{
		i = 1;
		while (i < ac)
		{
			if (ft_atoi(av[i]) >= 0 && ft_isdigit(av[i]))
				i++;
			else
				return (printf("Argument %d -> %s <- is Bad. \n", i, av[i]), 0);
		}
		return (1);
	}
	else
		printf("number of arguments is incorrect\n");
	return (0);
}
