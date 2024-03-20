/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:35:31 by dzurita           #+#    #+#             */
/*   Updated: 2024/02/28 14:55:19 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_errors_input(int ac, char *av)
{
	int	len;

	if (ac > 2)
	{
		ft_putstr_fd("Error\nToo many arguments\n", 2);
		exit(1);
	}
	if (ac <= 1)
	{
		ft_putstr_fd("Error\nNo arguments\n", 2);
		exit(1);
	}
	len = ft_strlen(av);
	if (len < 5 || av[len - 5] == '/')
	{
		ft_putstr_fd("Error\nMap name invalid\n", 2);
		exit(1);
	}
	if ((ft_strncmp(&av[len - 4], ".ber", 4)))
	{
		ft_putstr_fd("Error\nnot file .ber\n", 2);
		exit(1);
	}
}

void	ft_matrix_error(char *map_file, char **map, int type)
{
	if (type == 1)
		ft_putstr_fd("Error\nWalls are not correct\n", 2);
	if (type == 2)
		ft_putstr_fd("Error\nMap too big\n", 2);
	free(map_file);
	free_split_result(map);
	exit(1);
}

void	free_split_result(char **split_result)
{
	char	**temp;

	temp = split_result;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(split_result);
}

void	free_valid_map(char **dup_m, t_data *content)
{
	if (content->f_c == 0 && content->f_e == 0)
		free_split_result(dup_m);
	else
	{
		free_split_result(dup_m);
		free_split_result(content->map);
		free(content->map_file);
		ft_putstr_fd("Error\nCan not find path\n", 2);
		exit(1);
	}
}
