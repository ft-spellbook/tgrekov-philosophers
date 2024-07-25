/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:45:16 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/25 08:26:07 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../philo.h"

int				atoi_errable(const char *str, int *n);
int				atoul_errable(const char *str, unsigned long *n);
int				cancellable_sleep(unsigned long ms,
					int (*stop)(t_thread *thread), t_thread *thread);
int				err(const char *str, int retval);
int				ft_isspace(char c);
unsigned long	timestamp(void);
int				wrap_ix(int i, int max);

#endif