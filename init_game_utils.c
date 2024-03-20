/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:30:56 by dzurita           #+#    #+#             */
/*   Updated: 2024/02/26 17:37:22 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_cole *tex, t_data *content)
{
	content->texture = mlx_load_png("textures/Tiles.png");
	if (!content->texture)
		error_lib(content);
	tex->collecs = mlx_texture_to_image(content->mlx, content->texture);
	if (!tex->collecs)
		error_lib(content);
	mlx_resize_image(tex->collecs, 25, 25);
	content->tex = tex;
	mlx_delete_texture(content->texture);
}

void	error_lib(t_data *content)
{
	free(content->map_file);
	free_split_result(content->map);
	mlx_delete_image(content->mlx, content->walls);
	mlx_delete_image(content->mlx, content->player);
	mlx_delete_image(content->mlx, content->e);
	mlx_delete_image(content->mlx, content->img);
	mlx_delete_image(content->mlx, content->tex->collecs);
	mlx_delete_texture(content->texture);
	mlx_terminate(content->mlx);
	ft_putstr_fd("Error\nlib\n", 2);
	exit(EXIT_FAILURE);
}

void	get_collects(t_data *content)
{
	int	i;

	i = 0;
	while (content->c > i)
	{
		if (content->x == content->tex->collecs->instances[i].x / 50
			&& content->y == content->tex->collecs->instances[i].y / 50)
		{
			if (content->tex->collecs->instances[i].enabled == 1)
				content->co += 1;
			content->tex->collecs->instances[i].enabled = 0;
		}
		i++;
	}
	if (content->c == content->co)
	{
		if (mlx_image_to_window(content->mlx, content->e, content->e_x * 50,
				content->e_y * 50) < 0)
			error_lib(content);
	}
}
