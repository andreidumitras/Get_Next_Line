/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <adumitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:45:25 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/09 21:44:40 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// a test program for reading an entire file, line by line.
int main(int ac, char **av)
{
    char    *line;      // the line that will store a text line
    int     fd;         // a file descriptor for the opened file
    int     k;          // the line counter

    k = 0;
    ac--;
    // open the file sent as a command line argument
    fd = open(av[ac], O_RDONLY);
    // read the file described by fd, line by line using get_next_line()
    while (get_next_line(fd, &line) == 1)
    {
        k++;
        printf("liniea %d: ->%s\n", k, line);
    }
    close(fd);
    return (0);
}
