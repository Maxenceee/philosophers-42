/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:58:52 by mgama             #+#    #+#             */
/*   Updated: 2023/03/10 12:00:28 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

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
}
