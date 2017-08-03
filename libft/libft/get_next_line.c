/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 17:39:49 by msymkany          #+#    #+#             */
/*   Updated: 2017/01/30 14:41:21 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_lst	*get_fd(const int fd, t_lst **frst)
{
	t_lst		*lst;
	t_lst		*new;

	lst = *frst;
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	if (!(new = (t_lst *)malloc(sizeof(t_list))))
		return (NULL);
	new->fd = fd;
	new->data = NULL;
	new->next = *frst;
	*frst = new;
	return (new);
}

static int		read_line(char **cut, char **line, const int fd, ssize_t r)
{
	char		*n;
	char		*pt;
	size_t		i;

	while ((n = ft_strchr(*cut, '\n')) == NULL && r != 0)
	{
		i = ft_strlen(*cut);
		pt = ft_strdup(*cut);
		ft_strdel(cut);
		if (!(*cut = ft_strnew(i + BUFF_SIZE)) ||
			(r = read(fd, *cut + i, BUFF_SIZE)) < 0)
			return (-1);
		ft_memcpy(*cut, pt, i);
		ft_strdel(&pt);
	}
	if (r == 0 && n == NULL)
		n = ft_strchr(*cut, '\0');
	if (!(*line = ft_strsub(*cut, 0, n - *cut)))
		return (-1);
	n = ft_strdup(++n);
	ft_strdel(cut);
	if (!(*cut = ft_strdup(n)))
		return (-1);
	ft_strdel(&n);
	return (r == 0 && **line == '\0' && **cut == '\0') ? 0 : 1;
}

int				get_next_line(const int fd, char **line)
{
	static t_lst	*frst;
	t_lst			*lst;
	ssize_t			r;

	r = BUFF_SIZE;
	if (fd < 0 || !(line) || BUFF_SIZE <= 0)
		return (-1);
	lst = get_fd(fd, &frst);
	if (!lst->data)
	{
		if (!(lst->data = ft_strnew(BUFF_SIZE + 1)) ||
			(r = read(fd, lst->data, BUFF_SIZE)) < 0)
			return (-1);
	}
	return (read_line(&lst->data, line, fd, r));
}
