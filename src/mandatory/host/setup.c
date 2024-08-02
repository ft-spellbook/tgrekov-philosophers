/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 07:21:43 by tgrekov           #+#    #+#             */
/*   Updated: 2024/08/02 07:39:01 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file setup.c
 * @dontinclude setup.c
 * @line /\* *********
 * @until /\* *********
 */

#include <stdlib.h>
#include "../philosopher/philo.h"

/**
 * @brief Allocate fork and thread arrays
 * 
 * @param global 
 * @param thread 
 * @retval int 
 */
static int	allocate(t_global *global, t_thread **thread)
{
	*thread = 0;
	global->forks = malloc(sizeof(pthread_mutex_t) * global->opt.n);
	if (!global->forks)
		return (1);
	*thread = malloc(sizeof(t_thread) * global->opt.n);
	if (!*thread)
		return (1);
	return (0);
}

/**
 * @brief Initialize forks and eating quota mutexes
 * 
 * @param global 
 * @param thread
 * @retval int 
 */
static int	initialize(t_global *global, t_thread *thread)
{
	int	i;

	i = 0;
	while (i < global->opt.n && !pthread_mutex_init(&global->forks[i], 0))
		i++;
	if (i == global->opt.n)
	{
		if (!global->opt.eat_n)
			return (0);
		i = 0;
		while (i < global->opt.n && !pthread_mutex_init(&thread[i].full, 0))
			i++;
		if (i == global->opt.n)
			return (0);
		i++;
		while (i--)
			pthread_mutex_destroy(&thread[i].full);
		i = global->opt.n - 1;
	}
	i++;
	while (i--)
		pthread_mutex_destroy(&global->forks[i]);
	return (1);
}

/**
 * @brief Allocate fork array and thread structure,
 * initialize mutexes
 * 
 * @param global 
 * @param thread 
 * @retval int 
 */
int	setup(t_global *global, t_thread **thread)
{
	if (allocate(global, thread))
		return (1);
	if (pthread_mutex_init(&global->printing, 0))
		return (1);
	if (!pthread_mutex_init(&global->end_mutex, 0))
	{
		if (!initialize(global, *thread))
			return (0);
		pthread_mutex_destroy(&global->end_mutex);
	}
	pthread_mutex_destroy(&global->printing);
	return (1);
}
