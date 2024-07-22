/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:42:46 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/22 05:04:23 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	err(const char *str, int retval)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	write(2, str - len, len);
	return (retval);
}
