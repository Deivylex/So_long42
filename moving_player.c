/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:13:07 by dzurita           #+#    #+#             */
/*   Updated: 2024/02/26 17:25:07 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_data *content)
{
	if (content->map[content->y][content->x - 1] == '1')
		return ;
	else
	{
		content->player->instances[0].x -= 50;
		content->x -= 1;
		content->mv += 1;
		ft_printf("moves: %d\n", content->mv);
	}
	if (content->map[content->y][content->x] == 'E' &&
			content->co == content->c)
	{
		mlx_close_window(content->mlx);
		ft_printf("Great, you win the game!");
	}
	if (content->map[content->y][content->x] == 'C')
		get_collects(content);
}

void	move_right(t_data *content)
{
	if (content->map[content->y][content->x + 1] == '1')
		return ;
	else
	{
		content->x += 1;
		content->player->instances[0].x += 50;
		content->mv += 1;
		ft_printf("moves: %d\n", content->mv);
	}
	if (content->map[content->y][content->x] == 'C')
		get_collects(content);
	if (content->map[content->y][content->x] == 'E' &&
			content->co == content->c)
	{
		mlx_close_window(content->mlx);
		ft_printf("Great, you win the game!");
	}
}

void	move_up(t_data *content)
{
	if (content->map[content->y - 1][content->x] == '1')
		return ;
	else
	{
		content->player->instances[0].y -= 50;
		content->y -= 1;
		content->mv += 1;
		ft_printf("moves: %d\n", content->mv);
	}
	if (content->map[content->y][content->x] == 'C')
		get_collects(content);
	if (content->map[content->y][content->x] == 'E' &&
			content->co == content->c)
	{
		mlx_close_window(content->mlx);
		ft_printf("Great, you win the game!");
	}
}

void	move_down(t_data *content)
{
	if (content->map[content->y + 1][content->x] == '1')
		return ;
	else
	{
		content->player->instances[0].y += 50;
		content->y += 1;
		content->mv += 1;
		ft_printf("moves: %d\n", content->mv);
	}
	if (content->map[content->y][content->x] == 'C')
		get_collects(content);
	if (content->map[content->y][content->x] == 'E' &&
			content->co == content->c)
	{
		mlx_close_window(content->mlx);
		ft_printf("Great, you win the game!");
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*content;

	content = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(content->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(content);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_down(content);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(content);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(content);
}
