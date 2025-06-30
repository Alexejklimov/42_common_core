/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:39:31 by oklimov           #+#    #+#             */
/*   Updated: 2025/06/30 12:16:18 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	routine_lifecycle(t_philo *philo)
{
	while (!is_dead())
	{
		if (philo->eat_times_count == 0)
			break ;
		if (!grab_fork(philo))
		{
			usleep(100);
			continue ;
		}
		if (!omnomnom(philo))
		{
			pthread_mutex_unlock(&philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			break ;
		}
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		if (!ft_procrastination(philo))
			break ;
	}
}

static void	*start_routine(void *income)
{
	t_data	*data;
	t_philo	*philo;

	data = initton();
	philo = (t_philo *)income;
	if (data->philo_nb == 1)
		return (print_action(philo, "has taken a fork\n"),
			sleepy(data->time_to_die), print_action(philo, "died\n"), NULL);
	if (philo->ph_id % 2)
		usleep((data->time_to_eat / 2) * 1000);
	routine_lifecycle(philo);
	return (NULL);
}

void	init_data_struct(t_data *data, char	**av)
{
	data->philo_nb = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->nb_times_to_eat = ft_atoi(av[5]);
	else
		data->nb_times_to_eat = -42;
	data->die_flag = 0;
}

static void	init_philo_struct(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->philo_nb)
		pthread_mutex_init(&philo[i].left_fork, NULL);
	i = -1;
	while (data->philo_nb > ++i)
		philo[i].right_fork = &philo[(i + 1) % data->philo_nb].left_fork;
	philo[i].right_fork = &philo[0].left_fork;
	i = -1;
	while (data->philo_nb > ++i)
	{
		philo[i].ph_id = i + 1;
		philo[i].last_eat = timestamp();
		philo[i].eat_times_count = data->nb_times_to_eat;
		pthread_mutex_init(&philo[i].lock, NULL);
		pthread_mutex_init(&philo[i].count_lock, NULL);
	}
	pthread_mutex_init(&data->dead_mutex, NULL);
	pthread_mutex_init(&data->locker, NULL);
	pthread_mutex_init(&data->print_lock, NULL);
}

static void	start_lunch(t_data *data, t_philo *philo, char **av)
{
	int	i;

	i = -1;
	init_data_struct(data, av);
	init_philo_struct(data, philo);
	data->start_time = timestamp();
	while (data->philo_nb > ++i)
		pthread_create(&philo[i].tid, NULL, start_routine, &philo[i]);
	if (data->philo_nb > 1)
		is_philo_died(philo);
	i = -1;
	while (data->philo_nb > ++i)
		pthread_join(philo[i].tid, NULL);
	ft_destroy_mutex(philo, data);
}

int	main(int ac, char **av)
{
	static t_philo	*philo = NULL;
	t_data			*data;

	if (!check_arguments(ac, av))
		return (0);
	data = initton();
	philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!philo)
		return (write(1, "mall-err\n", 10), 0);
	start_lunch(data, philo, av);
	free(philo);
	return (0);
}
