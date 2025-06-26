/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:04:51 by oklimov           #+#    #+#             */
/*   Updated: 2025/06/26 17:32:45 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
				return (dead_unlock(philo, i), 0);
			pthread_mutex_unlock(&philo[i].lock);
			if (check_eat_count(philo) == 1)
			{
				pthread_mutex_lock(&data->dead_mutex);
				data->die_flag = 0;
				pthread_mutex_unlock(&data->dead_mutex);
			}
		}
		usleep(42);
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
