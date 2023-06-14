/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxencegama <maxencegama@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:30:54 by mgama             #+#    #+#             */
/*   Updated: 2023/06/14 12:51:14 by maxencegama      ###   ########.fr       */
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
	if (!mutexes)
		return (1);
	i = 0;
	while (i < M_NUM)
		pthread_mutex_init(&mutexes[i++], NULL);
	table->mutexes = mutexes;
	return (0);
}

int	init_philos(t_table *table)
{
	int				i;
	pthread_mutex_t	*forks;
	t_philo			*table_philos;
	// t_philo	temp_philo;

	forks = ft_calloc(table->number_of_philo, sizeof(pthread_mutex_t));
	if (!forks)
		return (1);
	table_philos = ft_calloc(table->number_of_philo + 1, sizeof(t_philo));
	if (!table_philos)
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
		// temp_philo.id = i;
		// temp_philo.eating_count = table->eating_count;
		// temp_philo.is_eating = 0;
		// temp_philo.is_sleeping = 0;
		// temp_philo.is_eating = 0;
		// temp_philo.has_fork = 0;
		// temp_philo.time_to_die = table->time_to_die;
		// temp_philo.time_to_eat = table->time_to_eat;
		// temp_philo.time_to_sleep = table->time_to_sleep;
		// table_philos[i] = temp_philo;
	}
	table->philos = table_philos;
	return (0);
}

int	ft_simulation(t_table *table)
{
	int				i;
	unsigned long	last_meal;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&table->mutexes[MEALS]);
		last_meal = table->philos[i].last_meal;
		pthread_mutex_unlock(&table->mutexes[MEALS]);
		if (last_meal && ft_abs_time() - last_meal > (unsigned int)table->time_to_die)
		{
			set_died(table);
			ft_print_state(&table->philos[i], "died");
			break ;
		}
		i = (i + 1) % table->number_of_philo;
		usleep(200);
	}
	return (0);
}

int	init_pthreads(t_table *table)
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
		// threads.args[i].table = table;
		threads.args[i].philo = &(table->philos[i]);
		if (pthread_create(threads.threads + i, NULL, philo_routine, (void *)&(threads.args[i])))
		{
			while (i--)
				pthread_join(threads.threads[i], NULL);
			return (printf("Couldn't create threads"), (void)free(threads.threads), 1);	
		}
	}
	ft_simulation(table);
	i = -1;
	while (++i < table->number_of_philo)
		pthread_join(threads.threads[i], NULL);
	table->threads = threads;
	// return ((void)ft_destroy_mutexes (philo, data), (void)free (th), 0);
	return (0);
}