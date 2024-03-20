/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:48:46 by dzurita           #+#    #+#             */
/*   Updated: 2024/02/28 14:56:11 by dzurita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	*map_file;
	t_data	content;
	t_cole	test;

	check_errors_input(ac, av[1]);
	map_file = open_file(av[1]);
	content.map_file = map_file;
	check_parameters_map(map_file, &content);
	av = ft_split(map_file, '\n');
	if (av == NULL)
	{
		free(map_file);
		exit(1);
	}
	check_is_rect(av, map_file, &content);
	content.map = av;
	content.map_file = map_file;
	check_valid_map(av, map_file, &content);
	open_window(&content);
	init_img(&test, &content);
	init_game(&content);
	free(map_file);
	free_split_result(av);
	return (EXIT_SUCCESS);
}
