/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:06:04 by mregrag           #+#    #+#             */
/*   Updated: 2024/04/30 18:56:42 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	if_philo_died(t_table *table)
{
	time_t	time;
	int		i;

	i = -1;
	time = get_time_in_ms();
	while (++i < table->nb_philos)
	{
		if (time - get_last_meal_time(table->philos[i]) == table->time_to_die)
		{
			print_status(table->philos[i], "died");
			set_diner_stop(table, 1);
			return (1);
		}
	}
	return (0);
}

static int	if_all_philo_full(t_table *table)
{
	int	i;
	int	full;

	i = -1;
	full = 0;
	while (++i < table->nb_philos)
		if (is_philo_full(table->philos[i]))
			full++;
	if (full == table->nb_philos)
	{
		set_diner_stop(table, 1);
		return (1);
	}
	return (0);
}

void	*observer(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	if (table->must_eat_meals == 0)
	{
		set_diner_stop(table, 1);
		return (NULL);
	}
	while (1)
		if (if_philo_died(table) || if_all_philo_full(table))
			return (NULL);
	return (NULL);
}
