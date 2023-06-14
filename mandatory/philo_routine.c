/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxencegama <maxencegama@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:06:28 by mgama             #+#    #+#             */
/*   Updated: 2023/06/08 18:25:27 by maxencegama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philo_routine(void *param)
{
	t_thread	*thread;
	t_philo		*philo;

	thread = (t_thread *)param;
	philo = thread->philo;
	if (thread->id % 2 == 0)
	{
		printf("%d is thinking", thread->id);
		ft_msleep (philo->table->time_to_eat);
	}
	while (1)
	{
		if (check_died(philo))
			break ;
		if (!ft_eating(philo))
			break ;
		ft_print_state(philo, "is thinking");
		ft_msleep(philo->table->time_to_think);
	}
	return (NULL);
}
