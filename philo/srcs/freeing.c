/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxencegama <maxencegama@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:58:52 by mgama             #+#    #+#             */
/*   Updated: 2023/06/14 17:13:31 by maxencegama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	ft_destroy_mutexes(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philo)
		pthread_mutex_destroy(&table->forks_r[i++]);
	i = 0;
	while (i < M_NUM)
		pthread_mutex_destroy(&table->mutexes[i++]);
}

void	free_table(t_table *table)
{
	if (table->forks_r)
		free(table->forks_r);
	if (table->philos)
		free(table->philos);
	if (table->mutexes)
		free(table->mutexes);
	if (table->threads.threads)
		free(table->threads.threads);
	if (table->threads.args)
		free(table->threads.args);
	ft_destroy_mutexes(table);
}
