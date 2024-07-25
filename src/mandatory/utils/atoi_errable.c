/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_errable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:30:45 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/25 08:26:47 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file atoi_errable.c
 * @dontinclude atoi_errable.c
 * @line /\* *********
 * @until /\* *********
 */

#include "utils.h"

int	atoi_errable(const char *str, int *n)
{
	static const int	ft_int_max = 2147483647;
	int					sign;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	*n = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (*n > ft_int_max / 10 || (*n == ft_int_max / 10 && *str > '7'))
			return (1);
		*n = *n * 10 + (*(str++) - '0');
	}
	*n = *n * sign;
	return (0);
}
