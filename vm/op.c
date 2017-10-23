/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:24:53 by msymkany          #+#    #+#             */
/*   Updated: 2017/10/12 14:25:01 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_op	g_op[17] =
{
	{live_op, 1, {T_DIR}, 1, 10, 0, DIR_SIZE},
	{ld_op, 2, {T_DIR | T_IND, T_REG}, 2, 5, 1, DIR_SIZE},
	{st_op, 2, {T_REG, T_IND | T_REG}, 3, 5, 1, DIR_SIZE},
	{add_op, 3, {T_REG, T_REG, T_REG}, 4, 10, 1, DIR_SIZE},
	{sub_op, 3, {T_REG, T_REG, T_REG}, 5, 10, 1, DIR_SIZE},
	{and_op, 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		1, DIR_SIZE},
	{or_op, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		1, DIR_SIZE},
	{xor_op, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		1, DIR_SIZE},
	{zjmp_op, 1, {T_DIR}, 9, 20, 0, 2},
	{ldi_op, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		1, (DIR_SIZE / 2)},
	{sti_op, 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		1, (DIR_SIZE / 2)},
	{fork_op, 1, {T_DIR}, 12, 800, 0, 2},
	{lld_op, 2, {T_DIR | T_IND, T_REG}, 13, 10, 1, DIR_SIZE},
	{lldi_op, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		1, (DIR_SIZE / 2)},
	{lfork_op, 1, {T_DIR}, 15, 1000, 0, (DIR_SIZE / 2)},
	{aff_op, 1, {T_REG}, 16, 2, 1, DIR_SIZE},
	{0, 0, {0}, 0, 0, 0, 0}
};
