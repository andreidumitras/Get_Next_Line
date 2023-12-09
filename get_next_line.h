/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <adumitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 18:36:23 by adumitra          #+#    #+#             */
/*   Updated: 2017/06/22 18:00:09 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include "libft.h"

#define BUFF_SIZE 10
#define VERIFICA(x) if (!x) return (-1);

// the structure implements a linked list which holds a line from a certain file-descriptor
typedef struct s_gnl
{
	char *text;				// the text line
	int fd;					// the file descriptor
	struct s_gnl *next;		// the pointer to the next file
} t_gnl;

int get_next_line(int const fd, char **line);

#endif
