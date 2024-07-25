/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:59:35 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/25 06:58:45 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_opt
{
	int	n;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	eat_n;
}	t_opt;

typedef struct t_global
{
	t_opt			opt;
	pthread_mutex_t	printing;
	pthread_mutex_t	*forks;
}	t_global;

typedef struct s_thread
{
	int			i;
	pthread_t	thread;
	t_global	*global;
}	t_thread;

#endif