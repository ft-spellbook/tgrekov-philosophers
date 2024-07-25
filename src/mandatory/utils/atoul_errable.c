/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoul_errable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:14:50 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/25 08:31:59 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file atoul_errable.c
 * @dontinclude atoul_errable.c
 * @line /\* *********
 * @until /\* *********
 */

#include "utils.h"

int	atoul_errable(const char *str, unsigned long *n)
{
	static const unsigned long	ft_int_max = 18446744073709551615UL;

	while (ft_isspace(*str) || *str == '+')
		str++;
	*n = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (*n > ft_int_max / 10 || (*n == ft_int_max / 10 && *str > '5'))
			return (1);
		*n = *n * 10 + (*(str++) - '0');
	}
	return (0);
}
