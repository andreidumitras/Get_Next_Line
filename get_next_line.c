/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 14:29:00 by adumitra          #+#    #+#             */
/*   Updated: 2017/06/23 14:32:02 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static  void    adauga(t_gnl **vf, char *text, int fd)
{
	t_gnl  *p;

	p = (t_gnl *)malloc(sizeof(t_gnl));
	p->fd = fd;
	p->text = text;
	p->next = *vf;
	*vf = p;
}

static	t_gnl	*vezi_lista(t_gnl **vf, int fd)
{
	t_gnl	*p;

	p = *vf;
	while (p)
	{
		if (p->fd == fd)
			return (p);
		p = p->next;
	}
	adauga(vf, "\0", fd);
	return (*vf);
}

int				get_next_line(int const fd, char **line)
{
	static	t_gnl	*vf;
	char			text[BUFF_SIZE + 1];
	t_gnl			*p;
	int				cat;
	int				copiat;

	if (fd < 0 || !line || read(fd, text, 0) < 0)
		return (-1);
	p = vezi_lista(&vf, fd);
	VERIFICA((*line = ft_strnew(0)))
	while ((cat = read(fd, text, BUFF_SIZE)))
	{
		text[cat] = '\0';
		VERIFICA((p->text = ft_strjoin(p->text, text)))
		if (ft_strchr(p->text, '\n'))
			break ;
	}
	if (cat < BUFF_SIZE && ft_strlen(p->text) == 0)
		return (0);
	copiat = (int)ft_strlen(ft_strcharcpy(*line, p->text, '\n'));
	if (copiat < (int)ft_strlen(p->text))
		p->text += copiat + 1;
	else
		ft_strclr(p->text);
	return (1);
}
