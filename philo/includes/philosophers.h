/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxencegama <maxencegama@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:26:12 by mgama             #+#    #+#             */
/*   Updated: 2023/06/14 14:58:51 by maxencegama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <stdint.h>
# include <time.h>
# include <sys/time.h>

struct	s_table;
struct	s_philo;
struct	s_render;
struct	s_thread;

typedef enum e_mutexes
{
	PRINT,
	MEALS,
	DONE,
	DIED,
	M_NUM
}	t_mutexes;

typedef struct s_philo
{
	int				id;
	int				has_fork;
	unsigned long	last_meal;
	int				lfork;
	int				rfork;
	pthread_mutex_t	*forks;
	// int		is_eating;
	// int		is_thinking;
	// int		is_sleeping;
	// int		time_to_die;
	// int		time_to_eat;
	// int		time_to_sleep;
	int				eating_count;
	struct s_table	*table;
}				t_philo;

typedef struct s_thread
{
	int				id;
	// struct s_table	*table;
	struct s_philo	*philo;
}				t_thread;

typedef struct s_render
{
	pthread_t	*threads;
	t_thread	*args;
}				t_render;

typedef struct s_table
{
	unsigned long	start_timestamp;
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				eating_count;
	
	int				is_dead;
	int				is_done;
	t_philo			*philos;
	t_render		threads;
	pthread_mutex_t	*mutexes;
}				t_table;

/* init */

int				ft_init(t_table *table, int argc, char **argv);
int				init_mutexes(t_table *table);
int				init_philos(t_table *table);
int				init_pthreads(t_table *table);

/* parsing */

int				parse_philo(int argc, char **argv, t_table *table);

/* philo_routine */

void			*philo_routine(void *params);
int				ft_simulation(t_table *table);

/* checks */

void			ft_print_state(t_philo *philo, char const *const a);
int				check_died(t_philo *philo);
int				check_done(t_philo *philo);
void			set_died(t_table *table);
void			set_done(t_table *table);


/* eating */

int				ft_start_eating(t_philo *philo);
int				ft_finish_eating(t_philo *philo);
int				ft_eating(t_philo *philo);

/* utils */

int				ft_max(int a, int b);
int				ft_min(int a, int b);

/* time */

unsigned long	ft_abs_time(void);
unsigned long	ft_current_time(unsigned long begin);
void			ft_msleep(unsigned long msec);

/* freeing */

void			free_table(t_table *table);

/* ft_utils */

int				ft_atoi(const char *str);
long int		ft_atol(const char *str);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);

#endif /* PHILOSOPHERS_H */