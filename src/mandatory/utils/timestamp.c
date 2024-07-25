/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 04:46:29 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/25 10:23:38 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file timestamp.c
 * @dontinclude timestamp.c
 * @line /\* *********
 * @until /\* *********
 */

#include <sys/time.h>

/**
 * @brief Millisecond timestamp since this function was first called
 * 
 * @retval unsigned long 
 */
unsigned long	timestamp(void)
{
	static unsigned long	start = 0;
	struct timeval			t;

	gettimeofday(&t, 0);
	if (!start)
		start = t.tv_sec * 1000 + t.tv_usec / 1000;
	return ((t.tv_sec * 1000 + t.tv_usec / 1000) - start);
}
