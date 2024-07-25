/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cancellable_sleep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 04:54:29 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/23 06:31:38 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

void	cancellable_sleep(unsigned long ms, int *cond)
{
	unsigned long	start;

	start = timestamp();
	while ((!cond || !*cond) && (timestamp() - start) < ms)
		usleep(250);
}
