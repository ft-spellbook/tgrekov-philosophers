/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 07:04:14 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/27 07:46:16 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file wrap_err.c
 * @dontinclude wrap_err.c
 * @line /\* *********
 * @until /\* *********
 */

#include "../philosopher/philo.h"

/**
 * @brief Utility for writing error code to an address without nullifying an
 * existing error
 * 
 * @param thread
 * @param n 
 * @retval int 
 */
int	wrap_err(t_thread *thread, int n)
{
	if (n)
		thread->err = n;
	return (n);
}
