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

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*sptr;

	sptr = (char *) s;
	i = 0;
	while (i < n)
	{
		sptr[i] = c;
		i++;
	}
	return (s);
}

int	ft_line_is_empty(char *line)
{
	int	k;

	k = 0;
	while (k < ARRAY_SIZE)
	{
		if (line[k] != '\n')
			return (0);
		k++;
	}
	return (1);
}

int	ft_update_i(int i)
{
	if (i == BUFFER_SIZE - 1)
		i = 0;
	else
		i++;
	return (i);
}

char	*ft_return_null(char *temp)
{
	free(temp);
	return (NULL);
}
