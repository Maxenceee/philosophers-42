/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxencegama <maxencegama@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:26:00 by mgama             #+#    #+#             */
/*   Updated: 2023/06/14 17:39:51 by maxencegama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;

	ft_bzero(&table, sizeof(t_table));
	if (ft_init(&table, argc, argv))
		return (free_table(&table), 1);
	return (free_table(&table), 0);
}
