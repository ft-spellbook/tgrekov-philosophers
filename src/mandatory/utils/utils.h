/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:45:16 by tgrekov           #+#    #+#             */
/*   Updated: 2024/08/25 12:37:23 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../philosopher/philo.h"

int				atoi_errable(const char *str, int *n);
int				err(const char *str, int retval);
int				ft_strlen(char *str);
int				intlen(int n);
int				ullen(unsigned long n);
unsigned long	timestamp(void);
int				wrap_ix(int i, int max);

#endif