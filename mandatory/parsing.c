/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxencegama <maxencegama@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:43:03 by mgama             #+#    #+#             */
/*   Updated: 2023/06/14 12:48:30 by maxencegama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	ft_is_numeric(char const *str)
{
	int	i;

	i = 0;
	if (*str == '+')
		str++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

static int	check_args(int argc, char **argv)
{
	if (argc < 5)
	{
		write(2, "Error: Too few arguments.\n", 26);
		return (1);
	}
	if (argc > 6)
	{
		write(2, "Error: Too many arguments.\n", 27);
		return (1);
	}
	while (argc-- > 1)
	{
		if (ft_is_numeric(argv[argc]) == 0)
		{
			write(2, "Error: Invalid character.\n", 26);
			return (1);
		}
		if (ft_atol(argv[argc]) > INT32_MAX || ft_atol(argv[argc]) < 0)
		{
			write(2, "Error: Out of range value.\n", 27);
			return (1);
		}
	}
	return (0);
}

int	parse_philo(int argc, char **argv, t_table *table)
{
	if (check_args(argc, argv))
		return (1);
	table->is_dead = 0;
	table->is_done = 0;
	table->start_timestamp = ft_abs_time();
	table->number_of_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->time_to_think = 0;
	if ((table->number_of_philo % 2) && (table->time_to_eat > table->time_to_sleep))
		table->time_to_think = 1 + (table->time_to_eat - table->time_to_sleep);
	if (argc == 5)
		table->eating_count = -1;
	else
		table->eating_count = ft_atoi(argv[5]);
	return (0);
}
