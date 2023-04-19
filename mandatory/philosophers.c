/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:26:00 by mgama             #+#    #+#             */
/*   Updated: 2023/04/19 15:21:26 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	create_pthreads(t_table *table)
{
	int			i;
	t_render	threads;

	threads.args = ft_calloc(table->number_of_philo, sizeof(t_thread));
	if (!threads.args)
		return (1);
	threads.threads = ft_calloc(table->number_of_philo, sizeof(pthread_t));
	if (!threads.threads)
		return (1);
	i =-1;
	while (++i < table->number_of_philo)
	{
		threads.args[i].id = i;
		threads.args[i].table = table;
		threads.args[i].philo = &(table->philos[i]);
		if (pthread_create(threads.threads + i, NULL, philo_routine, &(threads.args[i])) != 0)
			while (i--)
				pthread_join (threads.threads[i], NULL);
			return ((void)free (threads.threads), 1);
			
	}
	i = -1;
	while (++i < table->number_of_philo)
		pthread_join(threads.threads[i], NULL);
	table->threads = threads;
	return (0);
}

static int	create_philos(t_table *table)
{
	int		i;
	t_philo	temp_philo;
	t_philo	*table_philos;

	table_philos = ft_calloc(table->number_of_philo + 1, sizeof(t_philo));
	if (!table_philos)
		return (1);
	i = -1;
	while (++i < table->number_of_philo)
	{
		temp_philo.id = i;
		temp_philo.eating_count = table->eating_count;
		temp_philo.is_eating = 0;
		temp_philo.is_sleeping = 0;
		temp_philo.is_eating = 0;
		temp_philo.has_fork = 0;
		temp_philo.time_to_die = table->time_to_die;
		temp_philo.time_to_eat = table->time_to_eat;
		temp_philo.time_to_sleep = table->time_to_sleep;
		table_philos[i] = temp_philo;
	}
	table->philos = table_philos;
	return (0);
}

void	philosophers(t_table *table)
{
	printf("%i %i %i %i\n", table->number_of_philo, table->time_to_die, table->time_to_eat, table->time_to_sleep);
	table->philos = NULL;
	if (create_philos(table))
		return free_table(table);
	if (create_pthreads(table))
		return free_table(table);
}

int	main(int argc, char **argv)
{
	t_table	table;

	parse_philo(argc, argv, &table);
	philosophers(&table);
	return (0);
}