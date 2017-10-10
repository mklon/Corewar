/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:13:00 by amovchan          #+#    #+#             */
/*   Updated: 2017/03/22 23:00:54 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cast_di(va_list ap, t_srt *lst)
{
	char		*str;
	intmax_t	nbr;

	nbr = signed_size(ap, lst);
	str = ft_castnegativ(nbr, lst);
	str = ft_apostroph(str, lst);
	str = ft_accur_digits(str, lst);
	if (lst->accur == 0 && lst->width != -1 && lst->zero_or_minus == '1')
	{
		lst->space = ' ';
		lst->zero_or_minus = '0';
	}
	if (lst->zero_or_minus != '1' && lst->plus != '0')
		str = ft_plus(str, lst);
	else
	{
		str = ft_plus2(str, lst);
		if ((lst->accur > lst->width && lst->space == ' ' && lst->plus == '0')
				|| (lst->width == -1 && lst->space == ' '))
			str = ft_space(str, ' ', ((int)ft_strlen(str) + 1), lst);
		else if (lst->plus == '0' && lst->accur == -1 && lst->space == ' ')
			str[0] = ' ';
	}
	return (str);
}

char	*ft_cast_unsigned(va_list ap, t_srt *lst, int base)
{
	char		*str;
	uintmax_t	nbr;

	nbr = unsigned_size(ap, lst);
	str = ft_itoa_base(nbr, base);
	if (lst->letar == 'u')
		str = ft_apostroph(str, lst);
	str = ft_accur_digits(str, lst);
	if (nbr != 0 || (str[0] == '\0' && lst->letar == 'o'))
		str = ft_strhesh(str, lst);
	else
		str = ft_width(str, lst);
	if (lst->accur > lst->width && lst->space == ' ')
		str = ft_space(str, ' ', ((int)ft_strlen(str) + 1), lst);
	return (str);
}

char	*ft_cast_xl(va_list ap, t_srt *lst)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_cast_unsigned(ap, lst, 16);
	while (s[i])
	{
		s[i] = (char)ft_toupper(s[i]);
		i++;
	}
	return (s);
}

char	*ft_cast_dl(va_list ap, t_srt *lst)
{
	lst->size = 3;
	return (ft_cast_di(ap, lst));
}

char	*ft_cast_long(va_list ap, t_srt *lst, int base)
{
	char		*str;
	uintmax_t	nb;

	nb = va_arg(ap, uintmax_t);
	nb = (unsigned long int)nb;
	str = ft_itoa_base(nb, base);
	if (lst->letar == 'U')
		str = ft_apostroph(str, lst);
	str = ft_accur_digits(str, lst);
	if (nb != 0 || (str[0] == '\0' && lst->letar == 'O'))
		str = ft_strhesh(str, lst);
	if (lst->accur > lst->width + 1 && lst->space == ' ')
		str = ft_space(str, ' ', ((int)ft_strlen(str) + 1), lst);
	else
		str = ft_width(str, lst);
	return (str);
}
