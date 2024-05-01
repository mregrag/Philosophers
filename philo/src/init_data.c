/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:53:15 by mregrag           #+#    #+#             */
/*   Updated: 2024/04/30 18:57:44 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static pthread_mutex_t	*init_forks(t_table *table)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * table->nb_philos);
	if (!forks)
		return (error_free("error forks", table));
	i = -1;
	while (++i < table->nb_philos)
		pthread_mutex_init(&forks[i], NULL);
	return (forks);
}

static t_philo	**init_philosophers(t_table *table)
{
	t_philo	**philos;
	int		i;

	philos = malloc(sizeof(t_philo) * table->nb_philos);
	if (!philos)
		return (error_free("error philos", table));
	i = -1;
	while (++i < table->nb_philos)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
			return (error_free("error philos", table));
		philos[i]->table = table;
		philos[i]->meals_count = 0;
		philos[i]->id = i + 1;
		philos[i]->full = 0;
		philos[i]->l_fork = i;
		philos[i]->r_fork = i - 1;
		if (i == 0)
			philos[i]->r_fork = table->nb_philos - 1;
		pthread_mutex_init(&philos[i]->time_mutex, NULL);
		pthread_mutex_init(&philos[i]->count_mutex, NULL);
		pthread_mutex_init(&philos[i]->full_mutex, NULL);
	}
	return (philos);
}

t_table	*init_table(char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (error_free("error table", NULL));
	table->nb_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->diner_stop = 0;
	table->must_eat_meals = -1;
	if (argv[5])
		table->must_eat_meals = ft_atoi(argv[5]);
	pthread_mutex_init(&table->write_mutex, NULL);
	pthread_mutex_init(&table->stop_mutex, NULL);
	table->forks = init_forks(table);
	if (!table->forks)
		return (error_free("error forks", table));
	table->philos = init_philosophers(table);
	if (!table->philos)
		return (error_free("error philos", table));
	return (table);
}
