/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:44:15 by mregrag           #+#    #+#             */
/*   Updated: 2024/04/30 19:02:52 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->time_mutex);
	philo->last_meal_time = get_time_in_ms();
	pthread_mutex_unlock(&philo->time_mutex);
}

void	update_nb_meals_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->count_mutex);
	if (philo->table->must_eat_meals > 0)
		philo->meals_count++;
	pthread_mutex_unlock(&philo->count_mutex);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->r_fork]);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->table->forks[philo->l_fork]);
	print_status(philo, "has taken a fork");
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->table->forks[philo->r_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->l_fork]);
}

int	if_diner_stop(t_table *table)
{
	int	result;

	result = 0;
	pthread_mutex_lock(&table->stop_mutex);
	if (table->diner_stop == 1)
		result = 1;
	pthread_mutex_unlock(&table->stop_mutex);
	return (result);
}
