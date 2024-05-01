/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:51:48 by mregrag           #+#    #+#             */
/*   Updated: 2024/04/29 16:44:11 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_diner_stop(t_table *table, int state)
{
	pthread_mutex_lock(&table->stop_mutex);
	table->diner_stop = state;
	pthread_mutex_unlock(&table->stop_mutex);
}

int	get_nb_meals_eat(t_philo *philo)
{
	int	nb_meals;

	pthread_mutex_lock(&philo->count_mutex);
	nb_meals = philo->meals_count;
	pthread_mutex_unlock(&philo->count_mutex);
	return (nb_meals);
}

time_t	get_last_meal_time(t_philo *philo)
{
	time_t	time;

	pthread_mutex_lock(&philo->time_mutex);
	time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->time_mutex);
	return (time);
}

void	set_philo_full(t_philo *philo, int state)
{
	pthread_mutex_lock(&philo->full_mutex);
	philo->full = state;
	pthread_mutex_unlock(&philo->full_mutex);
}

int	is_philo_full(t_philo *philo)
{
	int	full;

	full = 0;
	pthread_mutex_lock(&philo->full_mutex);
	full = philo->full;
	pthread_mutex_unlock(&philo->full_mutex);
	return (full);
}
