/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 04:49:00 by jhurpy            #+#    #+#             */
/*   Updated: 2024/01/05 01:04:42 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

bool	open_file_img(t_data *data)
{
	NORTH.img = mlx_xpm_file_to_image(data->mlx, NORTH.addr,
			&NORTH.width, &NORTH.height);
	if (NORTH.img == NULL)
		return (false);
	init_image(&NORTH);
	SOUTH.img = mlx_xpm_file_to_image(data->mlx, SOUTH.addr,
			&SOUTH.width, &SOUTH.height);
	if (SOUTH.img == NULL)
		return (false);
	init_image(&SOUTH);
	WEST.img = mlx_xpm_file_to_image(data->mlx, WEST.addr,
			&WEST.width, &WEST.height);
	if (WEST.img == NULL)
		return (false);
	init_image(&WEST);
	EAST.img = mlx_xpm_file_to_image(data->mlx, EAST.addr,
			&EAST.width, &EAST.height);
	if (EAST.img == NULL)
		return (false);
	init_image(&EAST);
	return (true);
}

bool	check_hero_pos(t_data *data)
{
	if (HERO.x == 0 || HERO.y == 0 || HERO.x == -1 || HERO.y == -1)
		return (false);
	if (check_in_square(data->map, (int)HERO.y, (int)HERO.x) == false)
		return (false);
	return (true);
}

bool	check_valid_textures(t_data *data)
{
	if (check_extension(NORTH.addr, ".xpm") == false
		|| check_access_file(NORTH.addr) == false)
	{
		msg_error("North texture is not valid");
		return (false);
	}
	if (check_extension(SOUTH.addr, ".xpm") == false
		|| check_access_file(SOUTH.addr) == false)
	{
		msg_error("South texture is not valid");
		return (false);
	}
	if (check_extension(WEST.addr, ".xpm") == false
		|| check_access_file(WEST.addr) == false)
	{
		msg_error("West texture is not valid");
		return (false);
	}
	if (check_extension(EAST.addr, ".xpm") == false
		|| check_access_file(EAST.addr) == false)
	{
		msg_error("East texture is not valid");
		return (false);
	}
	return (true);
}
