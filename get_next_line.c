/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 14:29:00 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/21 21:32:02 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
The function adds a new element to the top of the stack
Parameters:
 - vf:      the head of the stack
 - text:    the text to be added ('\0' as default)
 - fd:      the file-descriptor to be added
Returns:
 - void
*/
static void adauga(t_gnl **vf, char *text, int fd)
{
    t_gnl  *p;      // the node to be allocated

    // allocate memory for a new node
    p = (t_gnl *)malloc(sizeof(t_gnl));
    // fill the new node with data
    p->fd = fd;
    p->text = text;
    // link the new node to the head of the stack
    p->next = *vf;
    // update the head of the stack
    *vf = p;
}

/*
The function searches the stack for the specified file descriptor.
Parameters:
 - vf:  the head of the stack
 - fd:  the file descriptor to be found

Returns:
 - the node which contains the file descriptor
 - N
*/
static t_gnl *vezi_lista(t_gnl **vf, int fd)
{
    t_gnl *p;       // index pointer for traversing the stack

    // perform a linear search for the file descriptor
    // place the pointer at the head of the stack
    p = *vf;
    // traverse each element
    while (p)
    {
        // if the file descriptor is found, the node is returned
        if (p->fd == fd)
            return (p);
        p = p->next;
    }
    // if the file descriptor is not found, a new element is added to the stack
    adauga(vf, "\0", fd);
    // return the head of the stack
    return (*vf);
}

/*
The function reads ALWAYS one line from a specified file descriptor.
Parameters:
 - fd:      the file-descriptor corresponding to a file
 - line:    the memory space in which the function read one line

Returns:
 - -1: input error
 - 0: the read succeded but the file reached its end
 - 1: the read succeded and the file still has content to be read
*/
int get_next_line(int const fd, char **line)
{
    static t_gnl *vf;               // the head of the stack where the file descriptors are stored
                                    // the stack is static for keeping the text where it left, until the program stops
    char text[BUFF_SIZE + 1];       // the text buffer
    t_gnl *p;                       // a routine pointer, used for stack operations
    int cat;                        // the amount of read characters
    int	copiat;                     // the amount of copied characters

    // verify that the given file descriptor is valid
    // verify that the given line pointer exists
    // verify if it can read from that file descriptor
    if (fd < 0 || !line || read(fd, text, 0) < 0)
        return (-1);
    // get the node corresponding to the file descriptor
    p = vezi_lista(&vf, fd);
    // check if line can hold a new empty string
    VERIFICA((*line = ft_strnew(0)))
    // while it can read BUFF_SIZE characters from the text file
    // try to concatenate text until finds a '\n'
    // if a '\n' is found, the loop is broken
    while ((cat = read(fd, text, BUFF_SIZE)))
    {
        // place '\0'
        text[cat] = '\0';
        // try to concatenate a new read string to the current reading string stored inside the node p.
        VERIFICA((p->text = ft_strjoin(p->text, text)))
        // checks for '\n'
        if (ft_strchr(p->text, '\n'))
            break ;
    }
    // verify if the file is at its end
    if (cat < BUFF_SIZE && ft_strlen(p->text) == 0)
        return (0);
    // copy text from p->text into the given line until a '\n' occurs
    copiat = (int)ft_strlen(ft_strcharcpy(*line, p->text, '\n'));
    // place the pointer to the text after '\n', or clear the string.
    if (copiat < (int)ft_strlen(p->text))
        p->text += copiat + 1;
    else
        ft_strclr(p->text);
    return (1);
}
