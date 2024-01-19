/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 04:49:00 by jhurpy            #+#    #+#             */
/*   Updated: 2024/01/19 18:40:49 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

static void	get_addr(t_draw *img)
{
	free(img->addr);
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
}

/*
The function open_file_img opens the texture files and stores the images
in the corresponding variables.
*/

bool	open_file_img(t_data *data)
{
	NORTH.img = mlx_xpm_file_to_image(data->mlx, NORTH.addr,
			&NORTH.tex_w, &NORTH.tex_h);
	if (NORTH.img == NULL)
		return (false);
	get_addr(&NORTH);
	SOUTH.img = mlx_xpm_file_to_image(data->mlx, SOUTH.addr,
			&SOUTH.tex_w, &SOUTH.tex_h);
	if (SOUTH.img == NULL)
		return (false);
	get_addr(&SOUTH);
	WEST.img = mlx_xpm_file_to_image(data->mlx, WEST.addr,
			&WEST.tex_w, &WEST.tex_h);
	if (WEST.img == NULL)
		return (false);
	get_addr(&WEST);
	EAST.img = mlx_xpm_file_to_image(data->mlx, EAST.addr,
			&EAST.tex_w, &EAST.tex_h);
	if (EAST.img == NULL)
		return (false);
	get_addr(&EAST);
	return (true);
}

/*
The function check_hero_pos checks if the hero position is valid.
Check if it is in the map and not in a wall.
*/

void	check_hero_pos(t_data *data)
{
	if (HERO.x == 0 || HERO.y == 0 || HERO.x == -1 || HERO.y == -1)
		msg_error(HERO_INVALID);
	check_in_square(data->map, (int)HERO.y, (int)HERO.x);
}

/*
The function check_valid_textures checks if the textures are valid.
Check if the file extension is .xpm and if the file is accessible.
*/

void	check_valid_textures(t_data *data)
{
	if (check_extension(NORTH.addr, ".xpm") == false
		|| check_access_file(NORTH.addr) == false)
		msg_error("North texture is not valid");
	if (check_extension(SOUTH.addr, ".xpm") == false
		|| check_access_file(SOUTH.addr) == false)
		msg_error("South texture is not valid");
	if (check_extension(WEST.addr, ".xpm") == false
		|| check_access_file(WEST.addr) == false)
		msg_error("West texture is not valid");
	if (check_extension(EAST.addr, ".xpm") == false
		|| check_access_file(EAST.addr) == false)
		msg_error("East texture is not valid");
}
