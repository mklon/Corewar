/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 17:28:33 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/23 13:46:23 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getdouble(va_list ap, t_srt *lst)
{
	if (lst->letar == 'F' || lst->letar == 'f')
		return (ft_cast_f(ap, lst));
	else if (lst->letar == 'e')
		return (ft_cast_e(ap, lst));
	else if (lst->letar == 'E')
		return (ft_cast_el(ap, lst));
	else if (lst->letar == 'g')
		return (ft_str_g(ap, lst));
	else if (lst->letar == 'G')
		return (ft_cast_gi(ap, lst));
	else if (lst->letar == 'A')
		return (ft_cast_al(ap, lst));
	else if (lst->letar == 'a')
		return (ft_cast_a(ap, lst));
	else
		return (ft_getstr(ap, lst));
}

char	*get_str(va_list ap, t_srt *lst)
{
	if (lst->letar == 'S' || (lst->letar == 's' && lst->size == 3))
		return (ft_print_wchar_str(ap, lst));
	else if (lst->letar == 's')
		return (ft_cest_str(ap, lst));
	else if (lst->letar == 'b')
		return (ft_castb(ap, lst));
	else
		return (ft_getdouble(ap, lst));
}

char	*ft_getstr(va_list ap, t_srt *lst)
{
	if (lst->letar == 'p')
		return (ft_strcast_p(ap, lst));
	else if (lst->letar == 'd' || lst->letar == 'i')
		return (ft_cast_di(ap, lst));
	else if (lst->letar == 'o')
		return (ft_cast_unsigned(ap, lst, 8));
	else if (lst->letar == 'D')
		return (ft_cast_dl(ap, lst));
	else if (lst->letar == 'O')
		return (ft_cast_long(ap, lst, 8));
	else if (lst->letar == 'u')
		return (ft_cast_unsigned(ap, lst, 10));
	else if (lst->letar == 'U')
		return (ft_cast_long(ap, lst, 10));
	else if (lst->letar == 'x')
		return (ft_cast_unsigned(ap, lst, 16));
	else if (lst->letar == 'b')
		return (ft_cast_unsigned(ap, lst, 2));
	else if (lst->letar == 'X')
		return (ft_cast_xl(ap, lst));
	else
		return (NULL);
}
