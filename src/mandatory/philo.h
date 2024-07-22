/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:59:35 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/22 05:11:18 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct s_opt
{
	int	n;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	eat_n;
}	t_opt;

typedef struct s_philo
{
	int	i;
	int	last_ate;
	int	n_ate;
}	t_philo;

#endif