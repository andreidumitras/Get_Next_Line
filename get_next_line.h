/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <adumitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 18:36:23 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/09 21:00:09 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include "libft.h"

#define BUFF_SIZE 10
// define a macro for shortening the code
#define VERIFICA(x) if (!x) return (-1);

// a linked list implementation for storing the text for each file descriptor opened with get_next_line().
// using a linked list achieves multiple file reading.
typedef struct s_gnl
{
	char *text;				// the text line
	int fd;					// the file descriptor
	struct s_gnl *next;		// the pointer to the next file
}			t_gnl;

// reads a single line from a file and stores it into the given parameter.
int	get_next_line(int const fd, char **line);

#endif
