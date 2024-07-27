/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 04:54:29 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/27 08:33:02 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file philo_sleep.c
 * 
 * @dontinclude philo_sleep.c
 * @line /\* *********
 * @until /\* *********
 */

#include <unistd.h>
#include "utils.h"
#include "../philosopher/philo.h"

/**
 * @brief Sleep in 200 microsecond intervals until @p ms millis have elapsed,
 * or @p stop has returned non-zero
 * 
 * @param ms Milliseconds to sleep
 * @param stop Function determining whether the thread needs to terminate
 * @param thread 
 * @retval int 
 */
int	philo_sleep(unsigned long ms,
	int (*stop)(t_thread *thread), t_thread *thread)
{
	unsigned long	start;
	int				stopped;

	start = timestamp();
	stopped = 0;
	while (!stopped && (timestamp() - start) < ms)
	{
		stopped = usleep(200);
		if (!stopped && stop)
			stopped = stop(thread);
	}
	return (stopped);
}
