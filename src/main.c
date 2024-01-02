/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:01:37 by jhurpy            #+#    #+#             */
/*   Updated: 2024/01/02 16:56:01 by ychen2           ###   ########.fr       */
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
		/*
		TEST THE RETURN DATA OF THE PARSING
		return the result in file: /tester/.test_parsing
		*/
		test_parsing(&data, "main - fail - main.c");
		/*
		END OF TEST
		*/
		free_data(&data);
		return (EXIT_FAILURE);
	}
	/*
	TEST THE RETURN DATA OF THE PARSING
	return the result in file: /tester/.test_parsing
	*/
	test_parsing(&data, "main - succes - main.c");
	/*
	END OF TEST
	*/
	/*
	From here:
	The map must be correctly initialized.
	We open the MiniLibX window
	and the program will wait for the user to press a key.
	*/
//new add
	data_init(&data);
	draw_minimap(&data);
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx, data_loop, &data);
	mlx_loop(data.mlx);
//new add end
	// free_data(&data);
	return (EXIT_SUCCESS);
}
