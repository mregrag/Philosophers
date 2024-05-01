/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:18:35 by mregrag           #+#    #+#             */
/*   Updated: 2024/04/30 16:46:23 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_status(t_philo *philo, char *status)
{
	time_t	time;

	time = get_time_in_ms() - philo->table->start_time;
	pthread_mutex_lock(&philo->table->write_mutex);
	if (if_diner_stop(philo->table))
	{
		pthread_mutex_unlock(&philo->table->write_mutex);
		return ;
	}
	printf("%ld %d %s\n", time, philo->id, status);
	pthread_mutex_unlock(&philo->table->write_mutex);
}
