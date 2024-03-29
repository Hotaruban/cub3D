/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:59:39 by jhurpy            #+#    #+#             */
/*   Updated: 2024/01/19 16:52:59 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

static void	init_texture(t_texture *texture)
{
	ft_memset(&texture->north, 0, sizeof(t_draw));
	ft_memset(&texture->south, 0, sizeof(t_draw));
	ft_memset(&texture->west, 0, sizeof(t_draw));
	ft_memset(&texture->east, 0, sizeof(t_draw));
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
	data->map_height = 0;
	init_hero(&data->hero);
	data->face_ang = -1;
}
