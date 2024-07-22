/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:21:41 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/22 05:02:36 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "philo.h"

int	seat(t_init_data data);

int	main(int argc, char **argv)
{
	t_init_data	data;
	int			status;

	if (atoi_errable(argv[1], &data.n) || data.n < 1)
		return (err("Number of philosophers must be between 1 and INT_MAX\n"));
	if (atoi_errable(argv[2], &data.tt_die) || data.tt_die < 1)
		return (err("Time to die must be between 1 and INT_MAX\n"));
	if (atoi_errable(argv[3], &data.tt_eat) || data.tt_eat < 1)
		return (err("Time to eat must be between 1 and INT_MAX\n"));
	if (atoi_errable(argv[4], &data.tt_sleep) || data.tt_sleep < 1)
		return (err("Time to sleep must be between 1 and INT_MAX\n"));
	data.eat_n = 0;
	if (argc == 6 && (atoi_errable(argv[5], &data.eat_n) || data.eat_n))
		return (err("Eat count must be between 1 and INT_MAX\n"));
	status = seat(data);
}
