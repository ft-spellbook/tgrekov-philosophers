/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 07:06:01 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/27 08:31:12 by tgrekov          ###   ########.fr       */
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
	if (thread->global->death_report
		|| (thread->global->opt.eat_n
			&& thread->times_ate == thread->global->opt.eat_n)
		|| thread->err)
		return (1);
	if (timestamp() - thread->last_meal >= thread->global->opt.tt_die)
	{
		thread->global->death_report = 1;
		thread->err = status(thread, "died", 0);
	}
	return (thread->global->death_report);
}
