/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:06:15 by msymkany          #+#    #+#             */
/*   Updated: 2017/10/12 13:06:17 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		check_n_flag(t_general *gen)
{
	size_t	i;
	size_t	k;
	size_t	j;

	i = 0;
	j = 1;
	k = MAX_PLAYERS - gen->champ_num;
	while (k > 0)
	{
		if (gen->n_flag[gen->champ_num + k] != 0)
			ft_error("bad order of numb after flag -n\n");
		k--;
	}
	while (++i <= gen->champ_num)
	{
		if (gen->n_flag[i] == 0)
		{
			gen->n_flag[i] = gen->no_flag[j];
			j++;
		}
	}
}

void		is_n_flag(char **args, size_t *i, t_general *gen)
{
	unsigned int	j;

	if (!args[*i + 1] || !args[*i + 2])
		ft_error("Not enough argumets\n");
	if (gen->champ_num == MAX_PLAYERS)
		ft_error("To many champions\n");
	j = is_valid_num(args[++(*i)], 'n');
	(gen->n_flag[j]) ? ft_error("Wrong num of player\n") : 0;
	if (is_champ(args[++(*i)]))
		gen->n_flag[j] = *i;
	else
		ft_error("Wrong type of file (-n flag)\n");
	gen->champ_num++;
}

int			is_flag(char **args, size_t *i, t_general *gen)
{
	if (args[*(i)][0] == '-')
	{
		if (ft_strequ(args[*i], "-v"))
			gen->visual = 1;
		else if (ft_strequ(args[*i], "-a"))
			gen->aff = 1;
		else if (ft_strequ(args[*i], "-d"))
		{
			if (!args[*i + 1])
				ft_error("Not enough argumets\n");
			gen->dump = is_valid_num(args[++(*i)], 'd');
		}
		else if (ft_strequ(args[*i], "-n"))
			is_n_flag(args, i, gen);
		else if (ft_strequ(args[*i], "-g"))
			gen->debug = 1;
		else if (ft_strequ(args[*i], "-l"))
			gen->alive = 1;
		else
			ft_error("Invalid flag\n");
		return (1);
	}
	return (0);
}

int			is_champ(char *arg)
{
	int		k;

	k = ft_strlen(arg);
	if (arg[k - 4] == '.' && arg[k - 3] == 'c' && arg[k - 2] == 'o'
		&& arg[k - 1] == 'r' && (arg[k] == '\0' || arg[k] == '\n'))
		return (1);
	else
		return (0);
}

void		read_args(int ar, char **av, t_general *gen)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 1;
	while (++i < (size_t)ar)
	{
		if (is_flag(av, &i, gen))
			;
		else if (is_champ(av[i]))
		{
			if (gen->champ_num == MAX_PLAYERS)
				ft_error("To many champions\n");
			gen->no_flag[j++] = i;
			gen->champ_num++;
		}
		else
			ft_error("Invalid input file\n");
	}
	if (gen->champ_num == 0)
		ft_error("No champions\n");
	check_n_flag(gen);
	read_players(av, gen);
	write_to_map(gen);
}
