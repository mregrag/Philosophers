/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:21:25 by mregrag           #+#    #+#             */
/*   Updated: 2024/04/30 18:50:08 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	eating(t_philo *philo)
{
	take_forks(philo);
	print_status(philo, "is eating");
	update_last_meal_time(philo);
	update_nb_meals_eaten(philo);
	if (get_nb_meals_eat(philo) == philo->table->must_eat_meals)
		set_philo_full(philo, 1);
	philo_sleep(philo->table, philo->table->time_to_eat);
	drop_forks(philo);
}

static void	sleeping(t_philo *philo)
{
	print_status(philo, "is sleeping");
	philo_sleep(philo->table, philo->table->time_to_sleep);
}

static	void	thinking(t_philo *philo)
{
	print_status(philo, "is thinking");
}

static void	*one_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(&philo->table->forks[philo->r_fork]);
	print_status(philo, "has taken a fork");
	philo_sleep(philo->table, philo->table->time_to_die);
	print_status(philo, "died");
	pthread_mutex_unlock(&philo->table->forks[philo->r_fork]);
	return (NULL);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->table->must_eat_meals == 0)
		return (NULL);
	if (philo->table->nb_philos == 1)
		return (one_philo(data));
	while (!if_diner_stop(philo->table))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
