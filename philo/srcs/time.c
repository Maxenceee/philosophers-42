/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:38:49 by mgama             #+#    #+#             */
/*   Updated: 2023/06/21 17:44:06 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

unsigned long	ft_abs_time(void)
{
	struct timeval	tv;
	unsigned long	s;
	unsigned long	u;

	if (gettimeofday(&tv, NULL) == -1)
		write(2, "Error: GETTIMEOFDAY(2)\n", 28);
	s = tv.tv_sec * 1000;
	u = tv.tv_usec / 1000;
	return (s + u);
}

unsigned long	ft_current_time(unsigned long begin)
{
	unsigned long	abs_time;

	abs_time = ft_abs_time();
	return (abs_time - begin);
}

void	ft_msleep(unsigned long msec, t_philo *philo)
{
	if (ft_abs_time() + msec > philo->last_meal + philo->table->time_to_die)
	{
		usleep(msec - (msec - philo->table->time_to_die));
		return (set_died(philo->table));
	}
	usleep(msec * 50);
	usleep(msec * 50);
	usleep(msec * 50);
	usleep(msec * 50);
	usleep(msec * 50);
	usleep(msec * 50);
	usleep(msec * 50);
	usleep(msec * 50);
	usleep(msec * 50);
	usleep(msec * 50);
	usleep(msec * 50);
	usleep(msec * 50);
	usleep(msec * 50);
	usleep(msec * 50);
	usleep(msec * 50);
	usleep(msec * 50);
	usleep(msec * 50);
	usleep(msec * 50);
	usleep(msec * 50);
	usleep(msec * 50);
}
