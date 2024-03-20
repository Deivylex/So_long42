/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:38:22 by dzurita           #+#    #+#             */
/*   Updated: 2024/02/26 17:45:26 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_walls(mlx_t *mlx, t_data *content, int x, int y)
{
	content->texture = mlx_load_png("textures/Buildings.png");
	if (!content->texture)
		error_lib(content);
	content->walls = mlx_texture_to_image(mlx, content->texture);
	if (!content->walls)
		error_lib(content);
	mlx_resize_image(content->walls, 50, 50);
	if (mlx_image_to_window(mlx, content->walls, x * 50, y * 50) < 0)
		error_lib(content);
	mlx_delete_texture(content->texture);
}

void	ft_player(mlx_t *mlx, t_data *content, int x, int y)
{
	content->x = x;
	content->y = y;
	content->texture = mlx_load_png("textures/Idle-Sheet.png");
	if (!content->texture)
		error_lib(content);
	content->player = mlx_texture_to_image(mlx, content->texture);
	if (!content->player)
		error_lib(content);
	mlx_resize_image(content->player, 50, 50);
	if (mlx_image_to_window(mlx, content->player, x * 50, y * 50) < 0)
		error_lib(content);
	mlx_delete_texture(content->texture);
}

void	ft_exit_game(mlx_t *mlx, t_data *content, int x, int y)
{
	content->e_x = x;
	content->e_y = y;
	content->texture = mlx_load_png("textures/Base-01.png");
	if (!content->texture)
		error_lib(content);
	content->e = mlx_texture_to_image(mlx, content->texture);
	if (!content->e)
		error_lib(content);
	mlx_resize_image(content->e, 50, 50);
	mlx_delete_texture(content->texture);
}

void	display_map(char **av, mlx_t *mlx, t_data *content)
{
	int	x;
	int	y;

	y = 0;
	while (av[y] != NULL)
	{
		x = 0;
		while (av[y][x])
		{
			if (av[y][x] == '1')
				ft_walls(mlx, content, x, y);
			if (av[y][x] == 'P')
				ft_player(mlx, content, x, y);
			if (av[y][x] == 'E')
				ft_exit_game(mlx, content, x, y);
			if (av[y][x] == 'C')
			{
				if (mlx_image_to_window(mlx, content->tex->collecs,
						x * 50, y * 56) < 0)
					error_lib(content);
			}
			x++;
		}
		y++;
	}
}

void	init_game(t_data *content)
{
	content->texture = mlx_load_png("textures/Background.png");
	if (!content->texture)
		error_lib(content);
	content->img = mlx_texture_to_image(content->mlx, content->texture);
	if (!content->img)
		error_lib(content);
	mlx_delete_texture(content->texture);
	mlx_resize_image(content->img, content->cols * 50, content->rows * 50);
	if (mlx_image_to_window(content->mlx, content->img, 0, 0) < 0)
		return ;
	content->co = 0;
	display_map(content->map, content->mlx, content);
	mlx_key_hook(content->mlx, &my_keyhook, content);
	mlx_loop(content->mlx);
	mlx_delete_image(content->mlx, content->walls);
	mlx_delete_image(content->mlx, content->player);
	mlx_delete_image(content->mlx, content->e);
	mlx_delete_image(content->mlx, content->img);
	mlx_delete_image(content->mlx, content->tex->collecs);
	mlx_terminate(content->mlx);
}
