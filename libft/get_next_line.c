/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:53:09 by dzurita           #+#    #+#             */
/*   Updated: 2023/11/21 13:41:44 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(char	*rem_data, char	*buffer, int fd)
{
	int	rb;

	rb = 1;
	while (rb > 0 && !ft_strchr(rem_data, '\n'))
	{
		rb = read (fd, buffer, BUFFER_SIZE);
		if (rb < 0)
		{
			free (rem_data);
			rem_data = NULL;
			return (NULL);
		}
		buffer[rb] = '\0';
		rem_data = ft_strjoin_gnl(rem_data, buffer);
	}
	return (rem_data);
}

char	*get_next_line(int fd)
{
	static char	*rem_data;
	char		*new_line;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rem_data = read_file(rem_data, buffer, fd);
	if (!rem_data || !rem_data[0])
	{
		free (rem_data);
		rem_data = NULL;
		return (NULL);
	}
	new_line = get_new_line(rem_data);
	if (!new_line)
	{
		free(rem_data);
		rem_data = NULL;
		return (NULL);
	}
	rem_data = get_rem_data(rem_data);
	return (new_line);
}
