/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklimov <oklimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:39:40 by oklimov           #+#    #+#             */
/*   Updated: 2025/06/20 17:23:41 by oklimov          ###   ########.fr       */
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
	int					die_flag;			// id someone died
	int					philo_nb;			// number of philos
	int					time_to_die;		// 
	int					time_to_eat;		//
	int					time_to_sleep;		//
	int					nb_times_to_eat;	// 
	t_time				start_time;			// 
	pthread_mutex_t		dead_mutex;			// mutex for dead check
	pthread_mutex_t		print_lock;			// protect output 
	pthread_mutex_t		*forks;				// ?????
	pthread_mutex_t		locker;				// protect
}	t_data;

typedef struct s_philo
{
	int					ph_id;  			// id
	int					die_flag;   		// is alive = 0  - dead = 1
	int					eat_times_count; 	// how many times has eaten (nb_times_to_eat)
	t_time				last_eat;  			// time from last meal
	pthread_t			tid;				// thread id
	pthread_mutex_t		left_fork;			// left fork adress
	pthread_mutex_t		*right_fork;		// r    f    adress
	pthread_mutex_t		lock;				// lock status
	pthread_mutex_t		count_lock;			// lock status
}	t_philo;

int						ft_atoi(const char *nptr);
int						ft_isdigit(char *c);
int						check_arguments(int ac, char **av);
void					init_data_struct(t_data *data, char	**av);
t_data					*initton(void);
t_time					timestamp(void);
int						print_action(t_philo *philo, char *str);
int						sleepy(t_time time);
int						is_dead(void);
int						ft_procrastination(t_philo *philo);
int						omnomnom(t_philo *philo);
void					grab_fork(t_philo *philo);




#endif
