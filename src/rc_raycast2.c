/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_raycast2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:29:19 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/04 19:37:42 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

static void	get_wall_hit_x(t_rays *rays, double wall_hit_x_db)
{
	wall_hit_x_db -= floor(wall_hit_x_db);
	rays->wall_hit_x = (wall_hit_x_db * rays->wall.width);
	if ((!rays->side_hit && rays->dir.x > 0) || (rays->side_hit && rays->dir.y < 0))
		rays->wall_hit_x = rays->wall.width - rays->wall_hit_x - 1;
}

void	get_crutial_val(t_data *data, t_rays *rays, double perp_angle)
{
	double	wall_hit_x_db;

	if (rays->side_hit)
	{
		rays->perp_dist = (rays->map.y - data->hero.y + (1 - rays->step.y) / 2);
		rays->perp_dist *= cos(perp_angle) / rays->dir.y;
		wall_hit_x_db = data->hero.x + rays->perp_dist * rays->dir.x;
		if (rays->dir.y > 0)
			rays->wall = data->texture.north;
		else
			rays->wall = data->texture.south;
	}
	else
	{
		rays->perp_dist = (rays->map.x - data->hero.x + (1 - rays->step.x) / 2);
		rays->perp_dist *= cos(perp_angle) / rays->dir.x;
		wall_hit_x_db = data->hero.y + rays->perp_dist * rays->dir.y;
		if (rays->dir.x > 0)
			rays->wall = data->texture.east;
		else
			rays->wall = data->texture.west;
	}
	get_wall_hit_x(rays, wall_hit_x_db);
}
