/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_errable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:30:45 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/22 04:36:18 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file atoi_errable.c
 * @dontinclude atoi_errable.c
 * @line /\* *********
 * @until /\* *********
 */

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	atoi_errable(const char *str, int *n)
{
	static const int	ft_int_max = 2147483647L;
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
	while (ft_isdigit(*str))
	{
		if (*n > ft_int_max / 10 || (*n == ft_int_max / 10 && *str > '7'))
			return (1);
		*n = *n * 10 + (*(str++) - '0');
	}
	*n = *n * sign;
	return (0);
}
