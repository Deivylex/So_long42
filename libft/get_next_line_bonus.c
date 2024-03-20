/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:37:28 by dzurita           #+#    #+#             */
/*   Updated: 2023/11/23 14:39:43 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*rem_data[1024];
	char		*new_line;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rem_data[fd] = read_file(rem_data[fd], buffer, fd);
	if (!rem_data[fd] || !rem_data[fd][0])
	{
		free (rem_data[fd]);
		rem_data[fd] = NULL;
		return (NULL);
	}
	new_line = get_new_line (rem_data[fd]);
	if (!new_line)
	{
		free(rem_data[fd]);
		rem_data[fd] = NULL;
		return (NULL);
	}
	rem_data[fd] = get_rem_data(rem_data[fd]);
	return (new_line);
}
