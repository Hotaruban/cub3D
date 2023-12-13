/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:01:37 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/14 00:58:18 by jhurpy           ###   ########.fr       */
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

	if (!check_error_file(ac, av[1]))
		return (1);
	data = ft_calloc(1, sizeof(t_data));
	init_data(data, av[1]);

	// Open the MiniLibX window

	return (0);
}
