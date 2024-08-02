/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 07:03:10 by tgrekov           #+#    #+#             */
/*   Updated: 2024/08/02 09:31:21 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file status.c
 * @dontinclude status.c
 * @line /\* *********
 * @until /\* *********
 */

#include <stdio.h>
#include "../utils/utils.h"
#include "philo.h"

/**
 * @brief Print status and verify correct length
 * 
 * @param thread 
 * @param ts 
 * @param str 
 * @retval int 
 */
static int	status_print_verify(t_thread *thread, unsigned long ts, char *str)
{
	return (printf("%lu %d %s\n", ts, thread->i + 1, str)
		!= (ullen(ts) + intlen(thread->i + 1) + ft_strlen(str) + 3));
}

/**
 * @brief Thread safe philosopher state logging
 * 
 * @param thread 
 * @param str 
 * @param ignore_end
 * @retval int 
 */
int	status(t_thread *thread, char *str, int ignore_end)
{
	unsigned long	ts;

	pthread_mutex_lock(&thread->global->printing);
	if (!ignore_end && check_end(thread->global))
		return (1);
	ts = timestamp();
	if (status_print_verify(thread, ts, str))
		thread->err = 1;
	pthread_mutex_unlock(&thread->global->printing);
	return (thread->err);
}
