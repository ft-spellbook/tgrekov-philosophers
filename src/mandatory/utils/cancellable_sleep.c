/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cancellable_sleep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 04:54:29 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/25 09:25:40 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"
#include "../philo.h"

int	cancellable_sleep(unsigned long ms,
	int (*stop)(t_thread *thread), t_thread *thread)
{
	unsigned long	start;
	int				stopped;

	start = timestamp();
	stopped = 0;
	while (!stopped && (timestamp() - start) < ms)
	{
		stopped = usleep(20);
		if (!stopped && stop)
			stopped = stop(thread);
	}
	return (stopped);
}
