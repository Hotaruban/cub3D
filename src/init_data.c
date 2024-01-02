/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:59:39 by jhurpy            #+#    #+#             */
/*   Updated: 2024/01/02 19:29:55 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

static void	init_img_texture(t_image *img)
{
	img->addr = NULL;
	img->img = NULL;
	img->height = 0;
	img->width = 0;
}

static void	init_texture(t_texture *texture)
{
	init_img_texture(&texture->north);
	init_img_texture(&texture->south);
	init_img_texture(&texture->west);
	init_img_texture(&texture->east);
	texture->floor = -1;
	texture->ceiling = -1;
}

static void	init_hero(t_cor_db *hero)
{
	hero->x = -1;
	hero->y = -1;
}

/*
The function init_data initialize the data structure.
*/

void	init_data(t_data *data)
{
	data->mlx = NULL;
	init_texture(&data->texture);
	data->map = NULL;
	init_hero(&data->hero);
	data->face_ang = -1;
}
