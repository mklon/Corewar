/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compiler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:36:16 by amovchan          #+#    #+#             */
/*   Updated: 2017/09/14 17:36:21 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_all	*ft_new_all(t_all *all)
{
	all = (t_all*)malloc(sizeof(t_all));
	all->header = (t_header*)malloc(sizeof(t_header));
	all->header->prog_size = 0;
	all->header->magic = COREWAR_EXEC_MAGIC;
	all->prog = NULL;
	all->stak = NULL;
	return (all);
}

static int		my_compile_file(int fd, char *str, char *name)
{
	int			i;
	t_all		*all;

	i = 0;
	all = ft_new_all(NULL);
	if (name_and_coment(fd, &i, &all) == -1)
	{
		ft_dell_all(&all);
		return (0);
	}
	if (translation_into_bytcode(fd, &i, NULL, &all) == -1)
	{
		ft_dell_all(&all);
		return (0);
	}
	ft_write_program(all, name);
	ft_dell_all(&all);
	return (1);
}

int				ft_compiler(char *str, char *name)
{
	int			fd;

	if (!(str[ft_strlen(str) - 1] == 's'
			&& str[ft_strlen(str) - 2] == '.'))
	{
		ft_printf("%{fd}s{fd}\n", 2,
				"Syntax error at token [TOKEN][001:001] END \"(null)\"", 2);
		return (0);
	}
	if ((fd = open(str, O_RDONLY)) == -1)
	{
		ft_printf("%{fd}s %{fd}s", 2, "Can't read source file", 2, str);
		close(fd);
		return (0);
	}
	else if (!my_compile_file(fd, str, name))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
