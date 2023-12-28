/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:59:39 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/27 14:44:05 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

static void	init_draw(t_draw *draw)
{
	draw->img = NULL;
	draw->addr = NULL;
	draw->bits_per_pixel = 0;
	draw->line_length = 0;
	draw->endian = 0;
}

static void	init_texture(t_texture *texture)
{
	init_draw(&texture->north);
	init_draw(&texture->south);
	init_draw(&texture->west);
	init_draw(&texture->east);
	texture->floor = -1;
	texture->ceiling = -1;
}

static void init_hero(t_pos *hero)
{
	hero->x = -1;
	hero->y = -1;
}

/*
The function init_data initialize the data structure.
*/

void	init_data(t_data *data)
{
	init_texture(&data->texture);
	data->map = NULL;
	init_hero(&data->hero);
	data->face_dir = 0;
}
