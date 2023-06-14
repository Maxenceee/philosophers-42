/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:43:03 by mgama             #+#    #+#             */
/*   Updated: 2023/05/16 14:29:14 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_args(int argc, char **argv)
{

}

int	parse_philo(int argc, char **argv, t_table *table)
{
	int			philo_c;
	int			i;
	long int	t;
	
	if (argc < 5 || argc > 6)
		return (printf("\033[1;31mInvalid arguments:\033[0m \033[4;36mnumber_of_philosophers\033[0m \033[4;36mtime_to_die\033[0m \033[4;36mtime_to_eat\033[0m \033[4;36mtime_to_sleep\033[0m \033[4;36m[number_of_times_each_philosopher_must_eat]\033[0m"), 1);
	i = 0;
	table->eating_count = -1;
	table->is_dead = 0;
	table->is_done = 0;
	table->start_timestamp = ft_abs_time();
	while (++i < argc)
	{
		t = ft_atol(argv[i]);
		if (t < 0)
			return (printf("\033[1;31mInvalid arguments:\033[0m negative numbers are not allowed"), 1);
		else if (t > INT32_MAX)
			return (printf("\033[1;31mInvalid arguments:\033[0m out of range"), 1);
		if (i == 1)
			table->number_of_philo = t;
		else if (i == 2)
			table->time_to_die = t;
		else if (i == 3)
			table->time_to_eat = t;
		else if (i == 4)
			table->time_to_sleep = t;
		else if (i == 5)
			table->eating_count = t;
	}
	return (0);
}
