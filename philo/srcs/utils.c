/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:20:11 by maxencegama       #+#    #+#             */
/*   Updated: 2023/06/14 18:13:56 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_max(int a, int b)
{
	if (b > a)
		return (b);
	return (a);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
