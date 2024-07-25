/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:21:41 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/25 06:59:08 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "philo.h"

int	seat(t_opt opt);

int	main(int argc, char **argv)
{
	t_opt	opt;
	int		res;

	if (atoi_errable(argv[1], &opt.n) || opt.n < 2 || opt.n > 1000)
		return (err("Number of philosophers must be between 2 and 1000\n", 1));
	if (atoi_errable(argv[2], &opt.tt_die) || opt.tt_die < 1)
		return (err("Time to die must be between 1 and INT_MAX\n", 1));
	if (atoi_errable(argv[3], &opt.tt_eat) || opt.tt_eat < 1)
		return (err("Time to eat must be between 1 and INT_MAX\n", 1));
	if (atoi_errable(argv[4], &opt.tt_sleep) || opt.tt_sleep < 1)
		return (err("Time to sleep must be between 1 and INT_MAX\n", 1));
	opt.eat_n = 0;
	if (argc == 6 && (atoi_errable(argv[5], &opt.eat_n) || opt.eat_n))
		return (err("Eat count must be between 1 and INT_MAX\n", 1));
	res = seat(opt);
}
