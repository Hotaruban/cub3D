/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_raycast2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:29:19 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/07 16:27:33 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

static void	get_wall_hit_x(t_rays *rays, double wall_hit_x_db)
{
	wall_hit_x_db -= floor(wall_hit_x_db);
	rays->wall_hit_x = (wall_hit_x_db * rays->wall.width);
	if ((!rays->side_hit && rays->dir.x < 0)
		|| (rays->side_hit && rays->dir.y > 0))
		rays->wall_hit_x = rays->wall.width - rays->wall_hit_x - 1;
}

void	get_crutial_val(t_data *data, t_rays *rays)
{
	double	wall_hit_x_db;

	if (rays->side_hit)
	{
		rays->perp_dist = rays->side_dist.y - rays->delta.y;
		wall_hit_x_db = data->hero.x + rays->perp_dist * rays->dir.x;
		if (rays->dir.y > 0)
			rays->wall = data->texture.south;
		else
			rays->wall = data->texture.north;
	}
	else
	{
		rays->perp_dist = rays->side_dist.x - rays->delta.x;
		wall_hit_x_db = data->hero.y + rays->perp_dist * rays->dir.y;
		if (rays->dir.x > 0)
			rays->wall = data->texture.east;
		else
			rays->wall = data->texture.west;
	}
	get_wall_hit_x(rays, wall_hit_x_db);
}
