/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:06:28 by mgama             #+#    #+#             */
/*   Updated: 2023/03/10 12:42:55 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philo_routine(void *param)
{
	t_thread	*thread;

	thread = (t_thread *)param;
	printf("%u start routine for philo %d\n", get_timestamp(thread->table), thread->id);
	fflush(NULL);
	return (NULL);
}