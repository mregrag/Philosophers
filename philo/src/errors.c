/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:01:15 by mregrag           #+#    #+#             */
/*   Updated: 2024/04/30 17:24:11 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	print_error(char *str, t_table *table)
{
	printf("%s\n", str);
	if (!table)
		free_table(table);
	return (EXIT_FAILURE);
}

void	*error_free(char *str, t_table *table)
{
	printf("%s\n", str);
	if (table != NULL)
		free_table(table);
	return (NULL);
}

void	destroy_mutexes(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->philos[i]->time_mutex);
		pthread_mutex_destroy(&table->philos[i]->full_mutex);
		pthread_mutex_destroy(&table->philos[i]->count_mutex);
		i++;
	}
	pthread_mutex_destroy(&table->write_mutex);
	pthread_mutex_destroy(&table->stop_mutex);
}

void	free_table(t_table *table)
{
	int	i;

	if (table == NULL)
		return ;
	if (table->forks != NULL)
		free(table->forks);
	if (table->philos != NULL)
	{
		i = -1;
		while (++i < table->nb_philos)
			if (table->philos[i] != NULL)
				free(table->philos[i]);
		free(table->philos);
	}
	destroy_mutexes(table);
	free(table);
}
