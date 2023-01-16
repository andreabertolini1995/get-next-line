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

#include "get_next_line.h"

void	ft_fill_line(int size, char *line, char *temp)
{
	int	k;

	k = 0;
	while (k < size)
	{
		line[k] = temp[k];
		k++;
	}
}

int	ft_calc_size(char *temp, char c)
{
	int	size;

	size = 0;
	while (temp[size] != '\n')
		size++;
	if (c == '\n')
		size++;
	return (size);
}

char	ft_end_of_file(int readout, char *line, int j)
{
	if (readout < 0 || (readout == 0 && ft_line_is_empty(line)))
		return (-1);
	if (readout == 0 && !ft_line_is_empty(line))
		return (line[j - 1]);
	else
		return (line[j]);
}

char	ft_read_line(int fd, char *buffer, char *temp)
{
	int			j;
	static int	i = 0;
	static int	readout;

	j = 0;
	while (i < BUFFER_SIZE)
	{
		if (i == 0)
			readout = read(fd, buffer, BUFFER_SIZE);
		if (readout <= 0)
			break ;
		while (i < readout)
		{
			temp[j] = buffer[i];
			if (buffer[i] == '\n')
			{
				i = ft_update_i(i);
				return (temp[j]);
			}
			j++;
			i++;
		}
		i = 0;
	}
	return (ft_end_of_file(readout, temp, j));
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE] = {0};
	char			*temp;
	char			*line;
	int				size;
	char			c;

	temp = (char *) malloc (sizeof(char) * ARRAY_SIZE);
	if (temp == NULL)
		return (NULL);
	memset(temp, '\n', ARRAY_SIZE);
	c = ft_read_line(fd, buffer, temp);
	if (temp == NULL)
		return (temp);
	if (c == -1)
		return (ft_return_null(temp));
	size = ft_calc_size(temp, c);
	line = (char *) malloc (sizeof(char) * (size + 1));
	if (line == NULL)
		return (ft_return_null(temp));
	ft_fill_line(size, line, temp);
	free(temp);
	line[size] = '\0';
	return (line);
}
