/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <adumitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:45:25 by adumitra          #+#    #+#             */
/*   Updated: 2017/06/22 17:44:40 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
	char *line;
	int fd;
	int k;

	k = 0;
	ac--;
	// open the file-descriptor sent in the command line arguments
	fd = open(av[ac], O_RDONLY);
	// reads the entire file, line by line
	while (get_next_line(fd, &line) == 1)
	{
		k++;
		printf("liniea %d: ->%s\n", k, line);
	}
	close(fd);
	return (0);
}
