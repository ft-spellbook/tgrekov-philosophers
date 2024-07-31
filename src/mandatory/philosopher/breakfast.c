/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breakfast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:55:23 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/31 07:12:23 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file breakfast.c
 * @dontinclude breakfast.c
 * @line /\* *********
 * @until /\* *********
 */

#include "../utils/utils.h"
#include "philo.h"

#include <stdio.h>

/**
 * @brief Take forks, eat, release
 * 
 * @param thread 
 * @param fork2 
 * @retval int 
 */
static int	eat(t_thread *thread, int fork2)
{
	int	res;

	pthread_mutex_lock(&thread->global->forks[thread->i]);
	if (stop(thread)
		|| wrap_err(thread, status(thread, "has taken a fork", 0, 0))
		|| (fork2 == thread->i
			&& philo_sleep(thread->global->opt.tt_die, stop, thread)))
		return (wrap_err(thread,
				pthread_mutex_unlock(&thread->global->forks[thread->i])) + 1);
	pthread_mutex_lock(&thread->global->forks[fork2]);
	res = 0;
	if (!stop(thread) && !wrap_err(thread,
			status(thread, "has taken a fork", "is eating", 0)))
	{
		thread->last_meal = timestamp();
		res = philo_sleep(thread->global->opt.tt_eat, stop, thread);
		if (++thread->times_ate == thread->global->opt.eat_n
			&& thread->global->opt.eat_n)
			pthread_mutex_unlock(&thread->full);
	}
	else
		res = 1;
	pthread_mutex_unlock(&thread->global->forks[thread->i]);
	pthread_mutex_unlock(&thread->global->forks[fork2]);
	return (res || thread->err);
}

/**
 * @brief Ponder, eat, sleep, repeat
 * 
 * @param arg 
 * @retval void* 
 */
void	*breakfast(void *arg)
{
	t_thread	*thread;

	thread = (t_thread *) arg;
	thread->last_meal = 0;
	thread->times_ate = 0;
	thread->err = 0;
	if (thread->global->opt.eat_n)
		pthread_mutex_lock(&thread->full);
	if (wrap_err(thread, status(thread, "is thinking", 0, 0)))
		return (0);
	if (thread->i % 2
		&& philo_sleep(thread->global->opt.tt_eat, stop, thread))
		return (0);
	while (!stop(thread)
		&& !eat(thread, wrap_ix(thread->i + 1, thread->global->opt.n))
		&& !wrap_err(thread, status(thread, "is sleeping", 0, 0))
		&& !philo_sleep(thread->global->opt.tt_sleep, stop, thread))
		wrap_err(thread, status(thread, "is thinking", 0, 0));
	if (thread->err)
	{
		pthread_mutex_lock(&thread->global->death_mutex);
		thread->global->death_report = 1;
		pthread_mutex_unlock(&thread->global->death_mutex);
	}
	return (0);
}
