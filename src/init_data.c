/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:59:39 by jhurpy            #+#    #+#             */
/*   Updated: 2024/01/02 15:54:15 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

static void	init_image(t_image *image)
{
	image->img = NULL;
	image->addr = NULL;
	image->width = 0;
	image->height = 0;
}

static void	init_texture(t_texture *texture)
{
	init_image(&texture->north);
	init_image(&texture->south);
	init_image(&texture->west);
	init_image(&texture->east);
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
	data->face_dir = 'C';
}
