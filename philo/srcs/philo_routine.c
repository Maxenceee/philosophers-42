/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:06:28 by mgama             #+#    #+#             */
/*   Updated: 2023/06/21 17:43:26 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_are_philo_done(t_table *table)
{
	int	i;
	int	done;
	int	meals_count;

	if (table->eating_count == -1)
		return (0);
	i = -1;
	done = -1;
	while (++i < table->number_of_philo)
	{
		pthread_mutex_lock(&table->mutexes[MEALS]);
		meals_count = table->philos[i].eating_count;
		pthread_mutex_unlock(&table->mutexes[MEALS]);
		if (meals_count >= table->eating_count)
			if (++done == table->number_of_philo - 1)
				return (1);
		usleep(50);
	}
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
		if (last_meal && ft_are_philo_done(table))
		{
			set_done(table);
			break ;
		}
		if (last_meal && ft_abs_time() - last_meal
			> (unsigned int)table->time_to_die)
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

void	*philo_routine(void *param)
{
	t_philo		*philo;

	philo = (t_philo *)param;
	if (philo->id % 2 == 0)
	{
		ft_print_state(philo, "is thinking");
		ft_msleep(philo->table->time_to_eat, philo);
	}
	while (1)
	{
		if (check_died(philo))
			break ;
		if (ft_eating(philo))
			break ;
		ft_print_state(philo, "is thinking");
		ft_msleep(philo->table->time_to_think, philo);
	}
	return (NULL);
}
