/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:41:24 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/28 12:56:49 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file sim_end.c
 * @dontinclude sim_end.c
 * @line /\* *********
 * @until /\* *********
 */

#include "philo.h"

/**
 * @brief Check if the simulation has ended
 * 
 * @param global
 * @retval int 
 */
int	check_end(t_global *global)
{
	int	end;

	pthread_mutex_lock(&global->end_mutex);
	end = global->end;
	pthread_mutex_unlock(&global->end_mutex);
	return (end);
}

int	set_end(t_global *global)
{
	int	was_set;

	pthread_mutex_lock(&global->end_mutex);
	was_set = global->end;
	global->end = 1;
	pthread_mutex_unlock(&global->end_mutex);
	return (was_set);
}
