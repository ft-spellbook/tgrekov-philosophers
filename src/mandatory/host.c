/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:55:35 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/25 08:38:16 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

void	*breakfast(void *data);

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

static int	create_threads(t_global *global, t_thread *thread)
{
	int		i;
	int		res;
	void	*tres;

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
		if (pthread_join(thread[i].thread, &tres) || tres)
			res = 1;
	}
	return (res);
}

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
