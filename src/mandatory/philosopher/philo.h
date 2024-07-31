/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:59:35 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/31 06:54:42 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philo.h
 * @dontinclude philo.h
 * @line /\* *********
 * @until /\* *********
 */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_opt
{
	int				n;
	unsigned long	tt_die;
	unsigned long	tt_eat;
	unsigned long	tt_sleep;
	int				eat_n;
}	t_opt;

typedef struct t_global
{
	t_opt			opt;
	pthread_mutex_t	printing;
	pthread_mutex_t	*forks;
	pthread_mutex_t	end_mutex;
	int				end;
}	t_global;

typedef struct s_thread
{
	int				i;
	pthread_t		thread;
	int				err;
	int				last_meal;
	int				times_ate;
	pthread_mutex_t	full;
	t_global		*global;
}	t_thread;

int	status(t_thread *thread, char *str, char *str2);
int	check_death(t_thread *thread);
int	stop(t_thread *thread);

#endif