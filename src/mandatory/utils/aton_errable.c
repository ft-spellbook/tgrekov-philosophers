/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aton_errable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:30:45 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/27 09:50:33 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file aton_errable.c
 * @dontinclude aton_errable.c
 * @line /\* *********
 * @until /\* *********
 */

#include "utils.h"

/**
 * @brief Converts ascii digits from @p str to a signed integer,
 * output into @p n . Returns 0 on success, 1 on overflow.
 * 
 * @param[in] str 
 * @param[out] n 
 * @retval int 
 */
int	atoi_errable(const char *str, int *n)
{
	static const int	ft_int_max = 2147483647;
	int					sign;

	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
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
	static const unsigned long	ft_ul_max = 18446744073709551615UL;

	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r' || *str == '+')
		str++;
	*n = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (*n > ft_ul_max / 10 || (*n == ft_ul_max / 10 && *str > '5'))
			return (1);
		*n = *n * 10 + (*(str++) - '0');
	}
	return (0);
}
