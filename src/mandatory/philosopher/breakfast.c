/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breakfast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:55:23 by tgrekov           #+#    #+#             */
/*   Updated: 2024/08/06 17:03:07 by tgrekov          ###   ########.fr       */
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
		|| status(thread, "has taken a fork", 0)
		|| (fork2 == thread->i
			&& philo_sleep(thread->global->opt.tt_die, thread)))
		return (pthread_mutex_unlock(&thread->global->forks[thread->i]) + 1);
	pthread_mutex_lock(&thread->global->forks[fork2]);
	res = 1;
	if (!status(thread, "has taken a fork", 0) && !stop(thread))
	{
		thread->last_meal = timestamp();
		res = status(thread, "is eating", 0);
		if (!res)
		{
			res = philo_sleep(thread->global->opt.tt_eat, thread);
			if (++thread->times_ate == thread->global->opt.eat_n
				&& thread->global->opt.eat_n)
				pthread_mutex_unlock(&thread->full);
		}
	}
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
	if (status(thread, "is thinking", 0))
		return (0);
	if (thread->i % 2
		&& philo_sleep(thread->global->opt.tt_eat, thread))
		return (0);
	while (!stop(thread)
		&& !eat(thread, wrap_ix(thread->i + 1, thread->global->opt.n))
		&& !status(thread, "is sleeping", 0)
		&& !philo_sleep(thread->global->opt.tt_sleep, thread))
		status(thread, "is thinking", 0);
	if (thread->err)
		set_end(thread->global);
	if (thread->global->opt.eat_n
		&& thread->times_ate < thread->global->opt.eat_n)
		pthread_mutex_unlock(&thread->full);
	return (0);
}
