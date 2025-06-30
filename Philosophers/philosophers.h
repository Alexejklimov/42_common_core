/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:39:40 by oklimov           #+#    #+#             */
/*   Updated: 2025/06/30 13:05:45 by oklimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

typedef long long		t_time;

typedef struct s_data
{
	int					die_flag;
	int					philo_nb;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_times_to_eat;
	t_time				start_time;
	pthread_mutex_t		dead_mutex;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		locker;
}	t_data;

typedef struct s_philo
{
	int					ph_id;
	int					eat_times_count;
	t_time				last_eat;
	pthread_t			tid;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		lock;
	pthread_mutex_t		count_lock;
}	t_philo;

t_data					*initton(void);
t_time					timestamp(void);
void					ft_destroy_mutex(t_philo *philo, t_data *data);
void					init_data_struct(t_data *data, char	**av);
void					dead_unlock(t_philo *philo, int i);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *nptr);
int						ft_isdigit(char *c);
int						check_arguments(int ac, char **av);
int						print_action(t_philo *philo, char *str);
int						sleepy(t_time time);
int						is_dead(void);
int						ft_procrastination(t_philo *philo);
int						omnomnom(t_philo *philo);
int						grab_fork(t_philo *philo);
int						is_philo_died(t_philo *philo);
int						check_eat_count(t_philo *philo);
int						get_die_flag(t_data *data);


void					print_grave(int philo_num, t_data *data);


#endif
