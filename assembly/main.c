/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 16:39:43 by amovchan          #+#    #+#             */
/*   Updated: 2017/10/13 15:00:40 by amovchan         ###   ########.fr       */
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
	while (++i < (int)(size - 1))
		src[i] = str[i];
	src[i] = '\0';
	leaks = src;
	src = ft_strjoin(src, "cor");
	ft_strdel(&leaks);
	return (src);
}

static void	ft_compile(char *str)
{
	char	*name;

	name = ft_name_file(str);
	if (ft_compiler(str, name))
	{
		ft_putstr("Writing output program to ");
		ft_putendl(name);
	}
	ft_strdel(&name);
}

int			main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
	{
		ft_printf("\a{fd}Usage: ./asm [-all] <sourcefile.s>\n\t%{fd}s\n", 2, 2,
		"-all : compiles all the arguments\n");
		return (0);
	}
	else if (argc > 1 && !ft_strcmp(argv[1], "-all"))
	{
		while (++i < argc)
			ft_compile(argv[i]);
	}
	else
		ft_compile(argv[argc - 1]);
	return (0);
}
