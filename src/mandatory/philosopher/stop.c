/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 07:06:01 by tgrekov           #+#    #+#             */
/*   Updated: 2024/08/06 17:19:52 by tgrekov          ###   ########.fr       */
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
 * @brief Determine if this thread's philo should die, or if the thread
 * has reported an error
 * 
 * @param thread 
 * @retval int 
 */
int	stop(t_thread *thread)
{
	if (thread->err)
		return (1);
	if (timestamp() - thread->last_meal
		>= (unsigned long) thread->global->opt.tt_die)
	{
		if (!set_end(thread->global))
			thread->err = status(thread, "died", 1);
		return (1);
	}
	return (0);
}
