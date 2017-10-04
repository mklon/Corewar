/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_fourth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 17:41:07 by oposhiva          #+#    #+#             */
/*   Updated: 2017/10/04 17:41:08 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	pc_color_down(t_general *gen, size_t i)
{
	if (gen->colors[i] == 5)
			gen->colors[i] = 1;
		else if (gen->colors[i] == 6)
			gen->colors[i] = 2;
		else if (gen->colors[i] == 7)
			gen->colors[i] = 3;
		else if (gen->colors[i] == 8)
			gen->colors[i] = 4;
}