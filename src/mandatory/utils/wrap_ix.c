/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_ix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrekov <tgrekov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:04:15 by tgrekov           #+#    #+#             */
/*   Updated: 2024/07/25 07:36:17 by tgrekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file wrap_ix.c
 * @dontinclude wrap_ix.c
 * @line /\* *********
 * @until /\* *********
 */

/**
 * @brief Wrap a circular index, such that indices below zero are equal to
 * <tt>max - i</tt> and indices above @p max continue from zero
 * 
 * @param[in] i 
 * @param[in] max 
 * @retval int 
 */
int	wrap_ix(int i, int max)
{
	if (i < 0)
		return (max + i);
	return (i % max);
}
