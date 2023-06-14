/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxencegama <maxencegama@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:30:54 by mgama             #+#    #+#             */
/*   Updated: 2023/06/14 17:13:58 by maxencegama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_init(t_table *table, int argc, char **argv)
{
	if (parse_philo(argc, argv, table))
		return (1);
	if (init_mutexes(table))
		return (1);
	if (init_philos(table))
		return (1);
	if (init_pthreads(table))
		return (1);
	return (0);
}

int	init_mutexes(t_table *table)
{
	pthread_mutex_t	*mutexes;
	int				i;

	mutexes = ft_calloc((size_t)(M_NUM), sizeof(pthread_mutex_t));
	table->mutexes = mutexes;
	if (!mutexes)
		return (1);
	i = 0;
	while (i < M_NUM)
		pthread_mutex_init(&mutexes[i++], NULL);
	return (0);
}

int	init_philos(t_table *table)
{
	int				i;
	pthread_mutex_t	*forks;
	t_philo			*table_philos;

	forks = ft_calloc(table->number_of_philo, sizeof(pthread_mutex_t));
	table->forks_r = forks;
	table_philos = ft_calloc(table->number_of_philo + 1, sizeof(t_philo));
	table->philos = table_philos;
	if (!table_philos || !forks)
		return (1);
	i = -1;
	while (++i < table->number_of_philo)
	{
		table_philos[i].id = i;
		table_philos[i].last_meal = table->start_timestamp;
		table_philos[i].eating_count = 0;
		table_philos[i].lfork = i;
		if (i == 0)
			table_philos[i].rfork = table->number_of_philo - 1;
		else
			table_philos[i].rfork = i - 1;
		table_philos[i].forks = forks;
		table_philos[i].table = table;
	}
	return (0);
}

int	init_pthreads(t_table *table)
{
	int			i;

	table->threads = ft_calloc(table->number_of_philo, sizeof(pthread_t));
	if (!table->threads)
		return (1);
	i = -1;
	while (++i < table->number_of_philo)
	{
		if (pthread_create(table->threads + i, NULL,
				philo_routine, (void *)&(table->philos[i])))
		{
			while (i--)
				pthread_join(table->threads[i], NULL);
			return (printf("Couldn't create threads\n"), 1);
		}
	}
	ft_simulation(table);
	i = -1;
	while (++i < table->number_of_philo)
		pthread_join(table->threads[i], NULL);
	return (0);
}
