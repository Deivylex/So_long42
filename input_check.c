/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:13:36 by dzurita           #+#    #+#             */
/*   Updated: 2024/02/28 14:50:48 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	extra_nwl(char *map_file)
{
	int	i;

	i = 0;
	if (map_file[0] == '\n')
	{
		ft_putstr_fd("Error\nextra newline\n", 2);
		free(map_file);
		exit(1);
	}
	while (map_file[i])
	{
		if ((map_file[i] == '\n' && map_file[i + 1] == '\n')
			|| (map_file[i] == '\n' && map_file[i + 1] == '\0'))
		{
			ft_putstr_fd("Error\nextra newline\n", 2);
			free(map_file);
			exit(1);
		}
		i++;
	}
}

void	enough_characters(char *map, t_data *content)
{
	int	player;
	int	e;
	int	collec;
	int	i;

	player = 0;
	e = 0;
	collec = 0;
	i = -1;
	while (map[++i])
	{
		if (map[i] == 'P')
			player++;
		if (map[i] == 'E')
			e++;
		if (map[i] == 'C')
			collec++;
	}
	if (player != 1 || e != 1 || collec == 0)
	{
		ft_putstr_fd("Error\nMissing a component\n", 2);
		free(map);
		exit(1);
	}
	content->c = collec;
}

void	check_parameters_map(char *map, t_data *content)
{
	char	*temp;

	extra_nwl(map);
	enough_characters(map, content);
	while (*map)
	{
		temp = map;
		while (*temp != '\0')
		{
			if (*temp != '0' && *temp != '1' && *temp != 'C'
				&& *temp != 'E' && *temp != 'P' && *temp != '\n')
			{
				ft_putstr_fd("Error\nInvalid characters\n", 2);
				free(map);
				exit(1);
			}
			temp++;
		}
		map++;
	}
}

void	check_is_rect(char **map, char *map_file, t_data *content)
{
	int		len;
	char	**tem;
	int		rows;
	int		len2;

	tem = map;
	len = ft_strlen(*map);
	if (len > 51)
		ft_matrix_error(map_file, map, 2);
	content->cols = len;
	rows = -1;
	while (tem[++rows] != NULL)
	{
		len2 = ft_strlen(tem[rows]);
		if (len != len2)
		{
			ft_putstr_fd("Error\nMap not rectangular\n", 2);
			free_split_result(map);
			free(map_file);
			exit(1);
		}
	}
	content->rows = rows;
	check_walls(map, map_file);
}

void	check_walls(char **map, char *map_file)
{
	int		i;
	int		len;
	char	**tem;

	tem = map;
	len = ft_strlen(*map);
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			ft_matrix_error(map_file, map, 1);
		i++;
	}
	i = 0;
	while (map[++i] != NULL)
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			ft_matrix_error(map_file, map, 1);
	if (i > 50)
		ft_matrix_error(map_file, map, 2);
	len = -1;
	while (map[i - 1][++len])
		if (map[i - 1][len] != '1')
			ft_matrix_error(map_file, map, 1);
}
