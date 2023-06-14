/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:26:00 by mgama             #+#    #+#             */
/*   Updated: 2023/05/16 14:06:54 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

// void	philosophers(t_table *table)
// {
// 	// printf("%i %i %i %i\n", table->number_of_philo, table->time_to_die, table->time_to_eat, table->time_to_sleep);
// 	table->philos = NULL;
// 	if (create_philos(table))
// 		return free_table(table);
// 	if (create_pthreads(table))
// 		return free_table(table);
// }

int	main(int argc, char **argv)
{
	t_table	table;

	ft_bzero(&table, sizeof(t_table));
	if (ft_init(&table, argc, argv))
		return (1);
	// philosophers(&table);
	return (0);
}