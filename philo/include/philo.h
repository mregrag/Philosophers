/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:33:41 by mregrag           #+#    #+#             */
/*   Updated: 2024/04/30 19:26:47 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <limits.h>
# include <time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
	pthread_t		t_thread;
	time_t			start_time;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	*forks;
	int				nb_philos;
	int				must_eat_meals;
	int				diner_stop;
	t_philo			**philos;
}	t_table;

typedef struct s_philo
{
	pthread_t		p_thread;
	int				id;
	int				meals_count;
	int				l_fork;
	int				r_fork;
	int				full;
	time_t			last_meal_time;
	pthread_mutex_t	time_mutex;
	pthread_mutex_t	count_mutex;
	pthread_mutex_t	full_mutex;
	t_table			*table;
}	t_philo;

int			ft_atoi(const char *str);
int			check_input(int ac, char **av);

void		update_last_meal_time(t_philo *philo);
void		update_nb_meals_eaten(t_philo *philo);
void		take_forks(t_philo *philo);
void		drop_forks(t_philo *philo);

void		*routine(void *data);

void		philo_sleep(t_table *table, time_t sleep_time);
time_t		get_time_in_ms(void);

void		*error_free(char *str, t_table *table);
void		free_table(t_table *table);
void		destroy_mutexes(t_table *table);
int			print_error(char *str, t_table *table);

t_table		*init_table(char **argv);

time_t		get_last_meal_time(t_philo *philo);
int			get_nb_meals_eat(t_philo *philo);
int			is_philo_full(t_philo *philo);

void		set_diner_stop(t_table *table, int stop);
void		set_philo_full(t_philo *philo, int state);

int			start_thread(t_table *table);
int			if_diner_stop(t_table *table);

void		print_status(t_philo *philo, char *status);

void		*observer(void *data);

#endif
