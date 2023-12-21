/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adumitra <adumitra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 17:42:57 by adumitra          #+#    #+#             */
/*   Updated: 2023/12/09 21:45:42 by adumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// clears the string specified as parameter
void    ft_strclr(char *s);

// fills with 0 the string
void    ft_bzero(void *s, size_t n);

// returns a new empty string of certain size
char    *ft_strnew(size_t size);

// returns a new string form the two strings sent as parameter concatenated.
char    *ft_strjoin(char const *s1, char const *s2);

// returns the pointer to where it finds the specified character inside the given string
char    *ft_strchr(const char *s, int c);

// returns the length of the given string
size_t  ft_strlen(const char *s);

// returns the destination where it copied the characters of src, until it hits the specified character c.
char    *ft_strcharcpy(char *dst, char *src, char c);

#endif
