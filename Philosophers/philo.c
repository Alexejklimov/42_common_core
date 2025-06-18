/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:39:31 by oklimov           #+#    #+#             */
/*   Updated: 2025/06/18 15:27:25 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_time	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((t_time)(tv.tv_sec * 1000LL + tv.tv_usec / 1000));

}

// static void	start_routine(void)
// {
	
// }

static void	start_lunch(t_data *data, t_philo *philo, int ac, char **av)
{
	int	i;

	init_data_struct(data, av);

	i = 0;
	while (data->philo_nb - 1 > i)
		philo[i].right_fork = &philo[i + 1].left_fork;
	philo[i].right_fork = &philo[0].left_fork;
	i = 0;
	while (data->philo_nb > i)
	{
		philo[i].ph_id = i;
		philo[i].last_eat = 0;
		philo[i].
	}

	// while (data->philo_nb < i)
	// {
	// 	pthread_create(&philo[i].tid, NULL, start_routine, &philo[i]);
	// }


}


int	main(int ac, char **av)
{
	t_data			*data;
	static t_philo	*philo;

	philo = NULL;
	if (!check_arguments(ac, av))
		return (0);
	data = initton();
	philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!philo || !data)
		return (write(1, "malloc error\n", 13), 0);

	start_lunch(data, philo, ac, av);
	init_data_struct(data, av);





	free(philo);
	return (0);
}
