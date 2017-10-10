/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_byt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:05:31 by amovchan          #+#    #+#             */
/*   Updated: 2017/10/10 17:23:36 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_check_last(char *str)
{
	int		len;
	char	*buf;
	int		i;

	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == '\n')
			break ;
		len--;
	}
	buf = ft_strdup(str + len);
	i = 0;
	ft_strdel(&str);
	while (buf[++i] && buf[i] < 33)
		;
	if (buf[i] == '\0' || buf[i] == COMMENT_CHAR || buf[i] == ';')
	{
		ft_strdel(&buf);
		return (0);
	}
	ft_strdel(&buf);
	return (-1);
}

int			last_byt(int fd)
{
	char	src[1024];
	char	*s;

	if (lseek(fd, 0, 0) < 0)
	{
		ft_printf("{fd}Error lseek\n", 2);
		return (-1);
	}
	s = NULL;
	ft_bzero(src, 1024);
	while (read(fd, src, 1024) > 0)
	{
		ft_strdel(&s);
		s = ft_strdup(src);
		ft_bzero(src, 1024);
	}
	if (ft_check_last(s) == -1)
		return (my_erormanager("", ft_tab(0, 0, 0), 10));
	return (0);
}
