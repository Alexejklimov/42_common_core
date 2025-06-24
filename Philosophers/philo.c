/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:39:31 by oklimov           #+#    #+#             */
/*   Updated: 2025/06/24 14:27:35 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_destroy_mutex(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_nb)
	{
		pthread_mutex_init(&philo[i].left_fork, NULL);
		pthread_mutex_init(&philo[i].lock, NULL);
	}
}

static void	*start_routine(void *income)
{
	t_data	*data;
	t_philo	*philo;

	data = initton();
	philo = (t_philo *)income;
	if (data->philo_nb == 1)
	{
		print_action(philo, "has taken a fork\n");
		sleepy(data->time_to_die);
		print_action(philo, "died\n");
		return (NULL);
	}
	if (philo->ph_id % 2)
		usleep((data->time_to_eat / 2) * 1000);
	while (is_dead())
	{
		grab_fork(philo);
		omnomnom(philo);
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		ft_procrastination(philo);
	}
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
	while (data->philo_nb - 1 > ++i)
		philo[i].right_fork = &philo[i + 1].left_fork;
	philo[i].right_fork = &philo[0].left_fork;
	i = -1;
	while (data->philo_nb > ++i)
	{
		philo[i].ph_id = i + 1;
		philo[i].last_eat = 0;
		philo[i].eat_times_count = data->nb_times_to_eat;
	}
	i = -1;
	while (++i < data->philo_nb)
	{
		pthread_mutex_init(&philo[i].left_fork, NULL);
		pthread_mutex_init(&philo[i].lock, NULL);
	}
	pthread_mutex_init(&data->locker, NULL);
	pthread_mutex_init(&data->print_lock, NULL);
}

static void	start_lunch(t_data *data, t_philo *philo, char **av)
// static void	start_lunch(t_data *data, t_philo *philo, int ac, char **av)
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
	if (!philo || !data)
		return (write(1, "malloc error\n", 13), 0);
	start_lunch(data, philo, av);
	free(philo);
	return (0);
}
