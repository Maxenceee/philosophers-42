/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:43:03 by mgama             #+#    #+#             */
/*   Updated: 2023/03/10 12:41:12 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	parse_philo(int argc, char **argv, t_table *table)
{
	int		philo_c;
	int		i;
	int		t;
	struct timeval  tv;
	
	if (argc < 5 || argc > 6)
	{
		printf("\033[1;31mInvalid arguments:\033[0m \033[4;36mnumber_of_philosophers\033[0m \033[4;36mtime_to_die\033[0m \033[4;36mtime_to_eat\033[0m \033[4;36mtime_to_sleep\033[0m \033[4;36m[number_of_times_each_philosopher_must_eat]\033[0m");
		exit(1);
	}
	i = 0;
	table->eating_count = -1;
	gettimeofday(&tv, NULL);
	table->start_timestamp = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	while (++i < argc)
	{
		t = ft_atoi(argv[i]);
		if (t < 0)
		{
			printf("\033[1;31mInvalid arguments:\033[0m negative numbers are not allowed");
			exit(1);
		}
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
}
