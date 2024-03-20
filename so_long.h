/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:46:43 by dzurita           #+#    #+#             */
/*   Updated: 2024/02/29 14:49:48 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/get_next_line.h"
# include "lib/MLX42/include/MLX42/MLX42.h"

typedef struct s_cole
{
	mlx_image_t	*collecs;
}	t_cole;

typedef struct s_data
{
	char			**map;
	char			*map_file;
	int				rows;
	int				cols;
	int				e_x;
	int				e_y;
	int				f_c;
	int				f_e;
	int				x;
	int				y;
	int				c;
	int				co;
	int				mv;
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	mlx_image_t		*player;
	mlx_image_t		*walls;
	t_cole			*tex;
	mlx_image_t		*e;
}	t_data;

void	check_errors_input(int ac, char *av);
void	ft_matrix_error(char *map_file, char **map, int type);
void	check_parameters_map(char *map, t_data *content);
void	check_is_rect(char **map, char *map_file, t_data *content);
void	free_split_result(char **split_result);
void	check_valid_map(char **map, char *map_file, t_data *content);
void	flood_fill(char **map, int row, int col, t_data *content);
void	check_walls(char **map, char *map_file);
char	**dup_map(char **map, char *map_file);
void	check_collec_map(char *map_file, int y, int x, t_data *content);
int		final_check_collects(char **av);
void	init_game(t_data *content);
void	init_img(t_cole *content, t_data *inf);
void	error_lib(t_data *content);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	get_collects(t_data *content);
void	open_window(t_data *content);
char	*open_file(char *file);
void	free_valid_map(char **dup_m, t_data *content);

#endif
