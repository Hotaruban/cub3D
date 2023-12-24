/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:01:37 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/24 16:05:40 by jhurpy           ###   ########.fr       */
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
	if (!check_error_file(ac, av[1]))
		return (1);
	data = allocate_memory(data);
	if (!data)
		return (1);
	init_data(data, av[1]);

	test_parsing(data, "main.c");

	/*
	From here:
	The map must be correctly initialized.
	We open the MiniLibX window and the program will wait for the user to press a key.
	*/

	return (0);
}
