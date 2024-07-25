/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 04:45:16 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/23 04:58:04 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int				atoi_errable(const char *str, int *n);
void			cancellable_sleep(unsigned long ms, int *cond);
int				err(const char *str, int retval);
unsigned long	timestamp(void);

#endif