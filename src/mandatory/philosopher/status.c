/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 07:03:10 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/27 07:54:56 by tgrekov          ###   ########.fr       */
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
 * @param str2
 * @retval int 
 */
int	status(t_thread *thread, char *str, char *str2)
{
	int				res;
	unsigned long	ts;

	res = 0;
	if (pthread_mutex_lock(&thread->global->printing))
		return (1);
	ts = timestamp();
	if (status_print_verify(thread, ts, str))
		res = 1;
	if (str2 && !res && status_print_verify(thread, ts, str2))
		res = 1;
	if (pthread_mutex_unlock(&thread->global->printing))
		return (1);
	return (res);
}
