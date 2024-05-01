/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:44:21 by mregrag           #+#    #+#             */
/*   Updated: 2024/04/30 19:32:09 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_isdigit(int c)
{
	return ((c >= 48 && c <= 57));
}

static int	is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == 45 || str[i] == 43))
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long	result;
	long	new_result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		new_result = result * 10 + (*str - 48);
		if (new_result < result && sign == 1)
			return (-1);
		if (new_result < result && sign == -1)
			return (0);
		str++;
		result = new_result;
	}
	return (result * sign);
}

int	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid(argv[i]))
			return (0);
		if (i == 1 && (ft_atoi(argv[i]) <= 0 || ft_atoi(argv[i]) > 200))
			return (0);
		if (i != 1 && (ft_atoi(argv[i]) < 0 || ft_atoi(argv[i]) > INT_MAX))
			return (0);
		i++;
	}
	return (1);
}
