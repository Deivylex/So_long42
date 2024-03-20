/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:54:52 by dzurita           #+#    #+#             */
/*   Updated: 2024/02/27 16:47:50 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_open_error(int fd, char *file)
{
	size_t	bytes_read;
	char	buffer[10];
	int		dir;

	if (fd == -1)
	{
		ft_putstr_fd("Error\nCan not open the file\n", 2);
		exit(1);
	}
	dir = open(file, O_DIRECTORY);
	if (dir != -1)
	{
		ft_putstr_fd("Error\nThe file is a directory\n", 2);
		close(dir);
		close(fd);
		exit(1);
	}
	bytes_read = read(fd, buffer, 10);
	if (buffer[0] == '\0')
	{
		ft_putstr_fd("Error\nEmpty file\n", 2);
		close(fd);
		exit(1);
	}
	close(fd);
}

void	free_open_file(char *map, int fd)
{
	ft_putstr_fd("Error\nMalloc\n", 2);
	free(map);
	close(fd);
	exit(1);
}

void	error_mlx(t_data *content)
{
	puts(mlx_strerror(mlx_errno));
	mlx_terminate(content->mlx);
	free(content->map_file);
	free_split_result(content->map);
	exit(EXIT_FAILURE);
}

char	*open_file(char *file)
{
	int		fd;
	char	*line;
	char	*map;
	char	*temp;

	map = NULL;
	temp = NULL;
	fd = open(file, O_RDONLY);
	ft_open_error(fd, file);
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp = ft_strjoin(map, line);
		free(line);
		if (!temp)
			free_open_file(map, fd);
		free(map);
		map = temp;
	}
	close (fd);
	return (map);
}

void	open_window(t_data *content)
{
	content->mlx = mlx_init(content->cols * 50, content->rows * 50,
			"so_long", true);
	if (!content->mlx)
		error_mlx(content);
}
