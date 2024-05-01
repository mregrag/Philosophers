/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:52:53 by mregrag           #+#    #+#             */
/*   Updated: 2024/04/30 17:00:53 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	start_thread(t_table *table)
{
	int	i;

	i = -1;
	table->start_time = get_time_in_ms();
	while (++i < table->nb_philos)
	{
		if (pthread_create(&table->philos[i]->p_thread,
				NULL, &routine, table->philos[i]))
			return (print_error("Error: Thread creation failed\n", table));
		usleep(100);
	}
	if (table->nb_philos > 1)
		if (pthread_create(&table->t_thread, NULL, &observer, table))
			return (print_error("Error: Thread creation failed\n", table));
	i = -1;
	while (++i < table->nb_philos)
		if (pthread_join(table->philos[i]->p_thread, NULL))
			return (print_error("Error: Thread join failed\n", table));
	if (table->nb_philos > 1)
		if (pthread_join(table->t_thread, NULL))
			return (print_error("Error: Thread join failed\n", table));
	return (1);
}
