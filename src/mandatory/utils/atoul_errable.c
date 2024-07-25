/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoul_errable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:14:50 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/25 10:22:54 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file atoul_errable.c
 * @dontinclude atoul_errable.c
 * @line /\* *********
 * @until /\* *********
 */

#include "utils.h"

/**
 * @brief Converts ascii digits from @p str to an unsigned long integer,
 * output into @p n . Returns 0 on success, 1 on overflow.
 * 
 * @param[in] str 
 * @param[out] n 
 * @retval int 
 */
int	atoul_errable(const char *str, unsigned long *n)
{
	static const unsigned long	ft_int_max = 18446744073709551615UL;

	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r' || *str == '+')
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
