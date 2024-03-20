/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:37:00 by dzurita           #+#    #+#             */
/*   Updated: 2024/02/26 16:49:22 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_valid_map(char **map, char *map_file, t_data *start)
{
	int		y;
	int		x;
	int		start_y;
	int		start_x;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				start_y = y;
				start_x = x;
			}
		}
	}
	check_collec_map(map_file, start_y, start_x, start);
}

char	**dup_map(char **map, char *map_file)
{
	int		i;
	char	**dup;

	i = 0;
	while (map[i] != NULL)
		i++;
	dup = (char **)malloc(sizeof(char *) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (map[i])
	{
		dup[i] = ft_strdup(map[i]);
		if (!dup[i])
		{
			free_split_result(dup);
			free_split_result(map);
			free(map_file);
			ft_putstr_fd("Error\nmalloc", 2);
			exit(1);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

void	check_collec_map(char *map_file,
		int y, int x, t_data *content)
{
	int		c;
	int		i;
	char	**dup;

	c = 0;
	i = 0;
	while (map_file[i])
	{
		if (map_file[i] == 'C')
			c++;
		i++;
	}
	content->f_c = c;
	content->f_e = 1;
	dup = dup_map(content->map, content->map_file);
	flood_fill(dup, y, x, content);
	free_valid_map(dup, content);
}

void	flood_fill(char **map, int row, int col, t_data *content)
{
	if (row < 0 || row >= content->rows || col < 0
		|| col >= content->cols || map[row][col] == '1')
		return ;
	if (map[row][col] == 'E')
		content->f_e--;
	if (map[row][col] == 'C')
		content->f_c--;
	map[row][col] = '1';
	if (final_check_collects(map) == 0)
	{
		content->f_c = 0;
		content->f_e = 0;
	}
	flood_fill(map, row - 1, col, content);
	flood_fill(map, row + 1, col, content);
	flood_fill(map, row, col - 1, content);
	flood_fill(map, row, col + 1, content);
}

int	final_check_collects(char **av)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (av[i])
	{
		x = 0;
		while (av[i][x])
		{
			if (av[i][x] != '1')
				y++;
			x++;
		}
		i++;
	}
	return (y);
}
