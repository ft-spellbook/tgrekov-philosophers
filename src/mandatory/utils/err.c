/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:42:46 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/25 07:10:47 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	err(const char *str, int retval)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	write(2, str - len - 1, len);
	return (retval);
}
