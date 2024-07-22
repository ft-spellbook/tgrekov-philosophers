/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:59:35 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/22 05:01:40 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct s_init_data
{
	int	n;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	eat_n;
}	t_init_data;

#endif