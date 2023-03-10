/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:26:12 by mgama             #+#    #+#             */
/*   Updated: 2023/03/10 12:42:21 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>

struct	s_table;
struct	s_philo;
struct	s_render;
struct	s_thread;


typedef struct s_philo
{
	int		id;
	int		has_fork;
	int		is_eating;
	int		is_thinking;
	int		is_sleeping;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		eating_count;
}				t_philo;

typedef struct s_thread
{
	int				id;
	struct s_table	*table;
	struct s_philo	*philo;
}				t_thread;

typedef struct s_render
{
	pthread_t	*threads;
	t_thread	*args;
}				t_render;

typedef struct s_table
{
	long int		start_timestamp;
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eating_count;
	t_philo			*philos;
	t_render		threads;
}				t_table;

/* parsing */

void	parse_philo(int argc, char **argv, t_table *table);

/* philo_routine */
void	*philo_routine(void *params);

/* time */
unsigned int	get_timestamp(t_table *table);

/* freeing */
void	free_table(t_table *table);

/* utils */
int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif /* PHILOSOPHERS_H */