/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:27:03 by amovchan          #+#    #+#             */
/*   Updated: 2016/12/16 19:56:56 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_nb_words(char const *str, char c)
{
	char	*p;
	int		cw;

	cw = 0;
	if (!*str)
		return (0);
	while (*str)
	{
		while (*str == c && *str)
			str++;
		p = (char *)str;
		while (*p != c && *p)
			p++;
		(*str != c && *str) ? cw++ : 0;
		str = p;
	}
	return (cw);
}
