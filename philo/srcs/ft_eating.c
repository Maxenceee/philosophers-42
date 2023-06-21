/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:14:24 by maxencegama       #+#    #+#             */
/*   Updated: 2023/06/21 17:42:53 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_start_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[ft_min(philo->lfork, philo->rfork)]);
	ft_print_state(philo, "has taken a fork");
	if (philo->lfork == philo->rfork)
	{
		pthread_mutex_unlock(&philo->forks[ft_min(philo->lfork, philo->rfork)]);
		return (1);
	}
	pthread_mutex_lock(&philo->forks[ft_max(philo->lfork, philo->rfork)]);
	ft_print_state(philo, "has taken a fork");
	ft_print_state(philo, "is eating");
	return (0);
}

int	ft_finish_eating(t_philo *philo)
{
	ft_print_state(philo, "is sleeping");
	pthread_mutex_unlock(&philo->forks[ft_max(philo->lfork, philo->rfork)]);
	pthread_mutex_unlock(&philo->forks[ft_min(philo->lfork, philo->rfork)]);
	ft_msleep(philo->table->time_to_sleep, philo);
	return (0);
}

int	ft_eating(t_philo *philo)
{
	if (ft_start_eating(philo) != 0)
		return (1);
	pthread_mutex_lock(&philo->table->mutexes[MEALS]);
	philo->last_meal = ft_abs_time ();
	philo->eating_count++;
	pthread_mutex_unlock(&philo->table->mutexes[MEALS]);
	if (check_done (philo))
	{
		ft_finish_eating(philo);
		return (1);
	}
	ft_msleep(philo->table->time_to_eat, philo);
	ft_finish_eating(philo);
	return (0);
}
