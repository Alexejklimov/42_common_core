/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:12:44 by oklimov           #+#    #+#             */
/*   Updated: 2025/06/30 13:08:32 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	print_action(t_philo *philo, char *str)
{
	t_data	*data;
	int		flag;

	data = initton();
	flag = get_die_flag(data);
	pthread_mutex_lock(&data->print_lock);
	if (flag && ft_strncmp(str, "died", 4) != 0)
	{
		pthread_mutex_unlock(&data->print_lock);
		return (0);
	}
	printf("%lld %d %s", timestamp() - data->start_time,
		philo->ph_id, str);
	pthread_mutex_unlock(&data->print_lock);
	return (0);
}

int	sleepy(t_time time)
{
	t_time	start;

	start = timestamp();
	while (timestamp() - start < time)
	{
		if (is_dead())
			return (0);
		usleep(100);
	}
	return (1);
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
		pthread_mutex_lock(&philo[i].count_lock);
		if (philo[i].eat_times_count == 0)
		{
			pthread_mutex_lock(&data->locker);
			count++;
			pthread_mutex_unlock(&data->locker);
		}
		pthread_mutex_unlock(&philo[i].count_lock);
	}
	if (count == data->philo_nb)
		return (1);
	return (0);
}

int	grab_fork(t_philo *philo)
{
	if (philo->ph_id % 2)
	{
		pthread_mutex_lock(&philo->left_fork);
		if (pthread_mutex_trylock(philo->right_fork) != 0)
			return (pthread_mutex_unlock(&philo->left_fork), 0);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		if (pthread_mutex_trylock(&philo->left_fork) != 0)
			return (pthread_mutex_unlock(philo->right_fork), 0);
	}
	if (is_dead())
	{
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	print_action(philo, "has taken a fork\n");
	print_action(philo, "has taken a fork\n");
	return (1);
}

int	omnomnom(t_philo *philo)
{
	t_data		*data;

	data = initton();
	pthread_mutex_lock(&philo->lock);
	philo->last_eat = timestamp();
	pthread_mutex_unlock(&philo->lock);
	if (!is_dead())
	{
		print_action(philo, "is eating\n");
		sleepy(data->time_to_eat);
	}
	pthread_mutex_lock(&philo->count_lock);
	if (philo->eat_times_count > 0)
		philo->eat_times_count--;
	pthread_mutex_unlock(&philo->count_lock);
	return (1);
}

int	ft_procrastination(t_philo *philo)
{
	t_data		*data;

	if (is_dead())
		return (0);
	data = initton();
	if (!is_dead())
		print_action(philo, "is sleeping\n");
	sleepy(data->time_to_sleep);
	if (is_dead())
		return (0);
	print_action(philo, "is thinking\n");
	if (data->philo_nb % 2)
	{
		if (data->time_to_eat >= data->time_to_sleep)
			usleep((data->time_to_eat - data->time_to_sleep) * 1000);
		usleep(100);
	}
	return (1);
}
