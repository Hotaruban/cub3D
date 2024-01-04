/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:01:37 by jhurpy            #+#    #+#             */
/*   Updated: 2024/01/04 23:03:01 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

/*
The function parse_user_arguments checks the validity of the arguments when
the program is launched.
*/

static bool	parse_user_arguments(int ac, char *path_map)
{
	if (ac != 2)
	{
		msg_error(NB_ARGS);
		return (false);
	}
	if (check_extension(path_map, ".cub") == false)
	{
		msg_error(EXTENSION);
		return (false);
	}
	if (check_access_file(path_map) == false)
	{
		msg_error(FILE_NOT_FOUND);
		return (false);
	}
	return (true);
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
	if (parse_user_arguments(ac, av[1]) == false)
		return (EXIT_FAILURE);
	init_data(&data);
	if (assign_data(&data, av[1]) == false)
	{
		free_data(&data);
		return (EXIT_FAILURE);
	}
	data_init(&data);
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx, data_loop, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
