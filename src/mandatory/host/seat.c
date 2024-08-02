/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 07:20:21 by tgrekov           #+#    #+#             */
/*   Updated: 2024/08/02 07:51:42 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file seat.c
 * @dontinclude seat.c
 * @line /\* *********
 * @until /\* *********
 */

#include <stdlib.h>
#include "../philosopher/philo.h"

int		setup(t_global *global, t_thread **thread);
void	*breakfast(void *data);

static void	monitor_eat_quota(t_global *global, t_thread *thread, int i)
{
	while (i--)
	{
		pthread_mutex_lock(&thread[i].full);
		pthread_mutex_unlock(&thread[i].full);
		pthread_mutex_destroy(&thread[i].full);
	}
	set_end(global);
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
			set_end(global);
			break ;
		}
	}
	if (global->opt.eat_n)
		monitor_eat_quota(global, thread, i);
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

	global.end = 0;
	global.opt = opt;
	if (!setup(&global, &thread))
	{
		create_threads(&global, thread);
		pthread_mutex_destroy(&global.printing);
		pthread_mutex_destroy(&global.end_mutex);
		i = 0;
		while (i < opt.n)
			pthread_mutex_destroy(&global.forks[i++]);
	}
	free(global.forks);
	free(thread);
	return (0);
}
