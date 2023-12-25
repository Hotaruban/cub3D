/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:01:37 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/25 14:06:17 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

/* ************************************************************************** */
/*                                                                            */
/*                            Launch the Game                                 */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	if (check_error_file(ac, av[1]) == false)
		return (EXIT_FAILURE);
	if (alloc_mem_init(data) == false)
		return (EXIT_FAILURE);
	if (assign_map_data(data, av[1]) == false)
		return (EXIT_FAILURE);

	test_parsing(data, "main.c");

	/*
	From here:
	The map must be correctly initialized.
	We open the MiniLibX window and the program will wait for the user to press a key.
	*/

	return (EXIT_SUCCESS);
}
