/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:33:54 by abertoli          #+#    #+#             */
/*   Updated: 2022/10/21 18:29:38 by abertoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define ARRAY_SIZE 1000000

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

char	*get_next_line(int fd);
char	ft_read_line(int fd, char *buffer, char *temp);
char	ft_end_of_file(int readout, char *line, int j);
int		ft_calc_size(char *temp, char c);
void	ft_fill_line(int size, char *line, char *temp);

void	*ft_memset(void *s, int c, size_t n);
int		ft_line_is_empty(char *line);
int		ft_update_i(int i);
char	*ft_return_null(char *temp);

#endif
