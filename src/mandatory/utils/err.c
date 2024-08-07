/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:42:46 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/27 08:36:38 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file err.c
 * @dontinclude err.c
 * @line /\* *********
 * @until /\* *********
 */

#include <unistd.h>

/**
 * @brief Write @p str to stderr and return @p retval
 * 
 * @param str 
 * @param retval 
 * @retval int 
 */
int	err(const char *str, int retval)
{
	int	len;

	len = 0;
	if (str)
	{
		while (*str++)
			len++;
		write(2, str - len - 1, len);
	}
	return (retval);
}
