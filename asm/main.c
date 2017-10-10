/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 16:39:43 by amovchan          #+#    #+#             */
/*   Updated: 2017/10/06 16:21:20 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*ft_name_file(char *str)
{
	char	*src;
	size_t	size;
	int		i;
	char	*leaks;

	size = ft_strlen(str);
	src = ft_strnew(size - 1);
	i = -1;
	while (++i < size - 1)
		src[i] = str[i];
	src[++i] = '\0';
	leaks = src;
	src = ft_strjoin(src, "cor");
	ft_strdel(&leaks);
	return (src);
}

int			main(int argc, char **argv)
{
	int		i;
	char	*name;

	i = 1;
	if (argc == 1)
		return (0);
	else if (argc > 1 && !ft_strcmp(argv[1], "-all"))
	{
		while (++i < argc)
		{
			name = ft_name_file(argv[i]);
			if (ft_compiler(argv[i], name))
				ft_printf("Writing output program to %s\n", name);
			ft_strdel(&name);
		}
	}
	else
	{
		name = ft_name_file(argv[argc - 1]);
		if (ft_compiler(argv[argc - 1], name))
			ft_printf("Writing output program to %s\n", name);
		ft_strdel(&name);
	}
	return (0);
}
