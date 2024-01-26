/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 04:49:00 by jhurpy            #+#    #+#             */
/*   Updated: 2024/01/27 00:39:32 by jhurpy           ###   ########.fr       */
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
	data->texture.north.img = mlx_xpm_file_to_image(data->mlx,
			data->texture.north.addr, &data->texture.north.tex_w,
			&data->texture.north.tex_h);
	if (data->texture.north.img == NULL)
		return (false);
	get_addr(&data->texture.north);
	data->texture.south.img = mlx_xpm_file_to_image(data->mlx,
			data->texture.south.addr, &data->texture.south.tex_w,
			&data->texture.south.tex_h);
	if (data->texture.south.img == NULL)
		return (false);
	get_addr(&data->texture.south);
	data->texture.west.img = mlx_xpm_file_to_image(data->mlx,
			data->texture.west.addr, &data->texture.west.tex_w,
			&data->texture.west.tex_h);
	if (data->texture.west.img == NULL)
		return (false);
	get_addr(&data->texture.west);
	data->texture.east.img = mlx_xpm_file_to_image(data->mlx,
			data->texture.east.addr, &data->texture.east.tex_w,
			&data->texture.east.tex_h);
	if (data->texture.east.img == NULL)
		return (false);
	get_addr(&data->texture.east);
	return (true);
}

/*
The function check_hero_pos checks if the hero position is valid.
Check if it is in the map and not in a wall.
*/

void	check_hero_pos(t_data *data)
{
	if (data->hero.x == 0 || data->hero.y == 0
		|| data->hero.x == -1 || data->hero.y == -1)
		msg_error(HERO_INVALID);
	check_in_square(data->map, (int)data->hero.y, (int)data->hero.x);
}

/*
The function check_valid_textures checks if the textures are valid.
Check if the file extension is .xpm and if the file is accessible.
*/

void	check_valid_textures(t_data *data)
{
	if (check_extension(data->texture.north.addr, ".xpm") == false
		|| check_access_file(data->texture.north.addr) == false)
		msg_error("North texture is not valid");
	if (check_extension(data->texture.south.addr, ".xpm") == false
		|| check_access_file(data->texture.south.addr) == false)
		msg_error("South texture is not valid");
	if (check_extension(data->texture.west.addr, ".xpm") == false
		|| check_access_file(data->texture.west.addr) == false)
		msg_error("West texture is not valid");
	if (check_extension(data->texture.east.addr, ".xpm") == false
		|| check_access_file(data->texture.east.addr) == false)
		msg_error("East texture is not valid");
}
