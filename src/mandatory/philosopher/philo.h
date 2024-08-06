/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:59:35 by tgrekov           #+#    #+#             */
/*   Updated: 2024/08/06 17:14:22 by tgrekov          ###   ########.fr       */
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
	int	n;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	eat_n;
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

int	philo_sleep(unsigned long ms, t_thread *thread);
int	status(t_thread *thread, char *str, int ignore_end);
int	check_end(t_global *global);
int	set_end(t_global *global);
int	stop(t_thread *thread);

#endif