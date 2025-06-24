/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:12:44 by oklimov           #+#    #+#             */
/*   Updated: 2025/06/20 17:25:35 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_action(t_philo *philo, char *str)
{
	t_data		*data;

	data = initton();
	pthread_mutex_lock(&data->print_lock);
	printf("%lld %d %s", (timestamp() - data->start_time), philo->ph_id, str);

	pthread_mutex_unlock(&data->print_lock);
	return (0);
}

int	sleepy(t_time time)
{
	t_time	start;

	start = timestamp();
	while (timestamp() - start < time)
		usleep(10);
	return (1);
}

int	is_dead(void)
{
	t_data	*data;

	data = initton();
	pthread_mutex_lock(&data->dead_mutex);
	if (!data->die_flag)
	{
		pthread_mutex_unlock(&data->dead_mutex);
		return (0);
	}
	pthread_mutex_unlock(&data->dead_mutex);
	return (1);
}


void	grab_fork(t_philo *philo)
{
	if (philo->ph_id % 2)
	{
		pthread_mutex_lock(&philo->left_fork);
		print_action(philo, "has taken a fork\n");
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork\n");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork\n");
		pthread_mutex_lock(&philo->left_fork);
		print_action(philo, "has taken a fork\n");
	}
}

int	omnomnom(t_philo *philo)
{
	t_data		*data;

	if (!is_dead() || philo->eat_times_count == 0)
		return (0);
	data = initton();
	pthread_mutex_lock(&philo->lock);
	philo->last_eat = timestamp() - data->start_time;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_lock(&philo->count_lock);
	if (philo->eat_times_count > 0)
		philo->eat_times_count--;
	pthread_mutex_unlock(&philo->count_lock);
	print_action(philo, "is eating\n");
	sleepy(data->time_to_eat);
	return (1);
}

int	ft_procrastination(t_philo *philo)
{
	t_data		*data;

	if (!is_dead())
		return (0);
	data = initton();
	print_action(philo, "is sleeping\n");
	sleepy(data->time_to_sleep);
	print_action(philo, "is thinking\n");
	if (data->philo_nb % 2)
	{
		if (data->time_to_eat >= data->time_to_sleep)
			usleep((data->time_to_eat - data->time_to_sleep) * 1000);
		usleep(500);
	}
	return (1);
}
