/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:55:23 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/25 10:30:24 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philosopher.c
 * @dontinclude philosopher.c
 * @line /\* *********
 * @until /\* *********
 */

#include <stdio.h>
#include "utils/utils.h"
#include "philo.h"

/**
 * @brief Thread safe philosopher state logging
 * 
 * @param thread 
 * @param str 
 */
static void	status(t_thread *thread, char *str)
{
	pthread_mutex_lock(&thread->global->printing);
	printf("%lu %d %s\n", timestamp(), thread->i + 1, str);
	pthread_mutex_unlock(&thread->global->printing);
}

/**
 * @brief Determine if this thread's philo should die or is full, or if another
 * philo has died
 * 
 * @param thread 
 * @retval int 
 */
static int	stop(t_thread *thread)
{
	return (thread->global->death_report
		|| (thread->global->opt.eat_n
			&& thread->times_ate == thread->global->opt.eat_n));
	if (timestamp() - thread->last_meal > thread->global->opt.tt_die)
	{
		thread->global->death_report = 1;
		status(thread, "died");
	}
	return (thread->global->death_report);
}

/**
 * @brief Take forks, eat, release
 * 
 * @param thread 
 * @param right_fork 
 * @retval int 
 */
static int	eat(t_thread *thread, int right_fork)
{
	int	res;

	pthread_mutex_lock(&thread->global->forks[thread->i]);
	if (stop(thread))
	{
		pthread_mutex_unlock(&thread->global->forks[thread->i]);
		return (1);
	}
	status(thread, "has taken a fork");
	pthread_mutex_lock(&thread->global->forks[right_fork]);
	res = 0;
	if (!stop(thread))
	{
		pthread_mutex_lock(&thread->global->printing);
		printf("%lu %d has taken a fork\n%lu %d is eating\n",
			timestamp(), thread->i + 1, timestamp(), thread->i + 1);
		pthread_mutex_unlock(&thread->global->printing);
		thread->last_meal = timestamp();
		thread->times_ate++;
		res = cancellable_sleep(thread->global->opt.tt_eat, stop, thread);
	}
	pthread_mutex_unlock(&thread->global->forks[thread->i]);
	pthread_mutex_unlock(&thread->global->forks[right_fork]);
	return (res);
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
	status(thread, "is thinking");
	if (thread->i % 2
		&& cancellable_sleep(thread->global->opt.tt_eat, stop, thread))
		return (0);
	while (!stop(thread))
	{
		if (eat(thread, wrap_ix(thread->i + 1, thread->global->opt.n)))
			return (0);
		status(thread, "is sleeping");
		if (cancellable_sleep(thread->global->opt.tt_sleep, stop, thread))
			return (0);
		status(thread, "is thinking");
	}
	return (0);
}
