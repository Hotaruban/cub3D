/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_raycast2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:29:19 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/04 18:37:38 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

static void	get_wall_hit_x(t_texture texture, t_rays *rays, double wall_hit_x_db, t_dir tex)
{
	wall_hit_x_db -= floor(wall_hit_x_db);
	if (tex == N)
		rays->wall = texture.north;
	else if (tex == E)
		rays->wall = texture.east;
	else if (tex == S)
		rays->wall = texture.south;
	else if (tex == W)
		rays->wall = texture.west;
	rays->wall_hit_x = (wall_hit_x_db * rays->wall.width);
	// if ((rays->side_hit == 0 && rays->dir.x > 0) || (rays->side_hit == 1 && rays->dir.y < 0))
	// 	rays->wall_hit_x = rays->wall.width - wall_hit_x_db - 1;
}

void	get_crutial_val(t_data *data, t_rays *rays)
{
	double	wall_hit_x_db;
	t_dir	tex;

	if (rays->side_hit)
	{
		rays->perp_dist = (rays->map.y - data->hero.y + (1 - rays->step.y) / 2) / rays->dir.y;
		wall_hit_x_db = data->hero.x + rays->perp_dist * rays->dir.x;
		if (rays->dir.y > 0)
			tex = S;
		else
			tex = N;
	}
	else
	{
		rays->perp_dist = (rays->map.x - data->hero.x + (1 - rays->step.x) / 2) / rays->dir.x;
		wall_hit_x_db = data->hero.y + rays->perp_dist * rays->dir.x;
		if (rays->dir.x > 0)
			tex = E;
		else
			tex = W;
	}
	get_wall_hit_x(data->texture, rays, wall_hit_x_db, tex);
}
