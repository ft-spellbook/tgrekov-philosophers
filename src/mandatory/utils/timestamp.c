/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 04:46:29 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/25 08:40:58 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

unsigned long	timestamp(void)
{
	static unsigned long	start = 0;
	struct timeval			t;

	gettimeofday(&t, 0);
	if (!start)
		start = t.tv_sec * 1000 + t.tv_usec / 1000;
	return ((t.tv_sec * 1000 + t.tv_usec / 1000) - start);
}
