/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:41:24 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/28 12:56:49 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file check_death.c
 * @dontinclude check_death.c
 * @line /\* *********
 * @until /\* *********
 */

#include "../utils/utils.h"
#include "philo.h"

int	check_death(t_thread *thread)
{
	int	dead;

	pthread_mutex_lock(&thread->global->death_mutex);
	dead = thread->global->death_report;
	pthread_mutex_unlock(&thread->global->death_mutex);
	return (dead);
}
