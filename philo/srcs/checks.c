/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:59:40 by mgama             #+#    #+#             */
/*   Updated: 2023/06/14 18:13:22 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_print_state(t_philo *philo, char const *const str)
{
	pthread_mutex_lock(&philo->table->mutexes[PRINT]);
	if (*str == 'd' || (!check_died(philo) && !check_done(philo)))
		printf("%lu %d %s\n",
			ft_current_time(philo->table->start_timestamp), philo->id, str);
	pthread_mutex_unlock (&philo->table->mutexes[PRINT]);
}

int	check_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->mutexes[DIED]);
	if (philo->table->is_dead)
	{
		pthread_mutex_unlock (&philo->table->mutexes[DIED]);
		return (1);
	}
	pthread_mutex_unlock (&philo->table->mutexes[DIED]);
	return (0);
}

int	check_done(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->mutexes[DONE]);
	if (philo->table->is_done)
	{
		pthread_mutex_unlock (&philo->table->mutexes[DONE]);
		return (1);
	}
	pthread_mutex_unlock (&philo->table->mutexes[DONE]);
	return (0);
}

void	set_died(t_table *table)
{
	pthread_mutex_lock(&table->mutexes[DIED]);
	table->is_dead = 1;
	pthread_mutex_unlock (&table->mutexes[DIED]);
}

void	set_done(t_table *table)
{
	pthread_mutex_lock(&table->mutexes[DONE]);
	table->is_done = 1;
	pthread_mutex_unlock (&table->mutexes[DONE]);
}
