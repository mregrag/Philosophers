/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:15:10 by mregrag           #+#    #+#             */
/*   Updated: 2024/04/30 17:31:04 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char *argv[])
{
	t_table	*table;

	table = NULL;
	if (argc != 5 && argc != 6)
		return (print_error("Error: Wrong number of arguments", table));
	if (check_input(argc, argv) == 0)
		return (print_error("invalid Input", table));
	table = init_table(argv);
	if (!table)
		return (EXIT_FAILURE);
	if (!start_thread(table))
		return (EXIT_FAILURE);
	free_table(table);
	return (EXIT_SUCCESS);
}
