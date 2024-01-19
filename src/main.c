/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:01:37 by jhurpy            #+#    #+#             */
/*   Updated: 2024/01/19 18:14:45 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

/*
The function parse_user_arguments checks the validity of the arguments when
the program is launched.
*/

static void	parse_user_arguments(int ac, char *path_map)
{
	if (ac != 2)
		msg_error(NB_ARGS);
	if (check_extension(path_map, ".cub") == false)
		msg_error(EXTENSION);
	if (check_access_file(path_map) == false)
		msg_error(FILE_NOT_FOUND);
}

/* ************************************************************************** */
/*                                                                            */
/*                            Launch the Game                                 */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(data));
	parse_user_arguments(ac, av[1]);
	init_data(&data);
	assign_data(&data, av[1]);
	data_init(&data);
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx, data_loop, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
