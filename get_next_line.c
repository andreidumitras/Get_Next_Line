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

/*
The function adds a new element to the stack
Parameters:
 - vf: the head of the stack
 - text: the text to be added ('\0' as default)
 - fd: the file-descriptor to be added
*/
static void adauga(t_gnl **vf, char *text, int fd)
{
	t_gnl  *p;

	// allocate memory for a new node
	p = (t_gnl *)malloc(sizeof(t_gnl));
	p->fd = fd;
	p->text = text;
	p->next = *vf;
	*vf = p;
}

/*
The function checks the stack to find the given file-descriptor. If not, a new element is created.
Parameters:
 - vf: the head of the list
 - fd: the file-descriptor to search by

Returns:
 - the memory address corresponding to the file-descriptor (contained or created)
*/
static t_gnl *vezi_lista(t_gnl **vf, int fd)
{
	t_gnl *p;

	// it performs a linear search for the given file-descriptor
	// if the file-descriptor is found, then, the corresponding pointer is returned
	p = *vf;
	while (p)
	{
		if (p->fd == fd)
			return (p);
		p = p->next;
	}
	// else, if the file-descriptor is not found, it is added to the head of the list, and then returned
	adauga(vf, "\0", fd);
	return (*vf);
}

/*
The function reads from a file until it completed a line delimited by '\n'. Than it fills the given line parameter.
Parameters:
 - fd: the file-descriptor corresponding to a file
 - line: the memory space in which the function read one line

Returns:
 - -1: input error
 - 0: the read succeded but the file reached its end
 - 1: the read succeded and the file still has content to be read
*/
int get_next_line(int const fd, char **line)
{
	static t_gnl *vf;				// the head of the queue where the file-descriptors are stored: static variable for keeping the text until the program stops
	char text[BUFF_SIZE + 1];			// the text buffer
	t_gnl *p;						// a routine pointer, used for queue operations
	int cat;						// the amount of read characters
	int copiat;						// the amount of copied characters

	// verify that the given file descriptor is valid
	// verify that the given line pointer exists
	// verify if it can read from that file descriptor
	if (fd < 0 || !line || read(fd, text, 0) < 0)
		return (-1);
	// place the pointer to the element corresponding to the file-descriptor
	p = vezi_lista(&vf, fd);
	// check if line can hold a new empty string
	VERIFICA((*line = ft_strnew(0)))
	// while it can read BUFF_SIZE characters from the text file, it tries to concatenate the each line of text until finds a '\n'
	// if a '\n' is found, the loop is broken
	while ((cat = read(fd, text, BUFF_SIZE)))
	{
		text[cat] = '\0';
		VERIFICA((p->text = ft_strjoin(p->text, text)))
		if (ft_strchr(p->text, '\n'))
			break ;
	}
	// if read() read the last line of text.
	if (cat < BUFF_SIZE && ft_strlen(p->text) == 0)
		return (0);
	// place text inside the given line pointer until '\n'
	copiat = (int)ft_strlen(ft_strcharcpy(*line, p->text, '\n'));
	// place the pointer to the text after '\n', or clear the string.
	if (copiat < (int)ft_strlen(p->text))
		p->text += copiat + 1;
	else
		ft_strclr(p->text);
	return (1);
}
