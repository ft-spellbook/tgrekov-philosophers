/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 07:06:01 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/31 05:30:01 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file stop.c
 * @dontinclude stop.c
 * @line /\* *********
 * @until /\* *********
 */

#include "../utils/utils.h"
#include "philo.h"

/**
 * @brief Determine if this thread's philo should die or is full, or if another
 * philo has died
 * 
 * @param thread 
 * @retval int 
 */
int	stop(t_thread *thread)
{
	if (thread->err
		|| (thread->global->opt.eat_n
			&& thread->times_ate == thread->global->opt.eat_n))
		return (1);
	if (timestamp() - thread->last_meal >= thread->global->opt.tt_die)
	{
		pthread_mutex_lock(&thread->global->death_mutex);
		thread->global->death_report = 1;
		pthread_mutex_unlock(&thread->global->death_mutex);
		thread->err = status(thread, "died", 0, 1);
		return (1);
	}
	return (0);
}
