/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:59:35 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/27 07:50:35 by tgrekov          ###   ########.fr       */
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
	int				death_report;
}	t_global;

typedef struct s_thread
{
	int			i;
	pthread_t	thread;
	int			err;
	int			last_meal;
	int			times_ate;
	t_global	*global;
}	t_thread;

int	status(t_thread *thread, char *str, char *str2);
int	stop(t_thread *thread);

#endif