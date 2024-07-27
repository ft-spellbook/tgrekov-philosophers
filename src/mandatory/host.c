/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:55:35 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/27 08:23:39 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file host.c
 * @dontinclude host.c
 * @line /\* *********
 * @until /\* *********
 */

#include <stdlib.h>
#include "philosopher/philo.h"

void	*breakfast(void *data);

/**
 * @brief Allocate array of forks and threads
 * 
 * @param global 
 * @param threads 
 * @retval int 
 */
static int	allocate(t_global *global, t_thread **threads)
{
	*threads = 0;
	global->forks = malloc(sizeof(pthread_mutex_t) * global->opt.n);
	if (!global->forks)
		return (1);
	*threads = malloc(sizeof(t_thread) * global->opt.n);
	if (!*threads)
		return (1);
	return (0);
}

/**
 * @brief Initialize forks and printing mutexes
 * 
 * @param global 
 * @retval int 
 */
static int	initialize(t_global *global)
{
	int	i;

	if (pthread_mutex_init(&global->printing, 0))
		return (1);
	i = 0;
	while (i < global->opt.n && !pthread_mutex_init(&global->forks[i], 0))
		i++;
	if (i < global->opt.n)
	{
		while (i--)
			pthread_mutex_destroy(&global->forks[i + 1]);
		pthread_mutex_destroy(&global->printing);
		return (1);
	}
	return (0);
}

/**
 * @brief Spawn philos and wait for them to complete
 * 
 * @param global 
 * @param thread 
 * @retval int 
 */
static int	create_threads(t_global *global, t_thread *thread)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (i < global->opt.n && !res)
	{
		thread[i].i = i;
		thread[i++].global = global;
		if (pthread_create(&thread[i - 1].thread, 0,
				breakfast, (void *) &thread[i - 1]))
		{
			res = 1;
			break ;
		}
	}
	while (i--)
	{
		if (pthread_join(thread[i].thread, 0) || thread[i].err)
			res = 1;
	}
	return (res);
}

/**
 * @brief Allocate for, initialize, seat, wait on (pun intended),
 * and free all philos
 * 
 * @param opt 
 * @retval int 
 */
int	seat(t_opt opt)
{
	t_global		global;
	t_thread		*thread;
	int				i;

	global.death_report = 0;
	global.opt = opt;
	if (!allocate(&global, &thread))
	{
		if (!initialize(&global))
		{
			create_threads(&global, thread);
			pthread_mutex_destroy(&global.printing);
			i = 0;
			while (i < opt.n)
				pthread_mutex_destroy(&global.forks[i++]);
		}
	}
	free(global.forks);
	free(thread);
	return (0);
}
