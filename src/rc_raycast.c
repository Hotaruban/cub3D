/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:29:19 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/02 18:02:23 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

static void	ray_cast_init(t_data *data, t_rays *rays)
{
	rays->map.x = (int)data->hero.x;
	rays->map.y = (int)data->hero.y;
	rays->delta.x = fabs(1 / rays->dir.x);
	rays->delta.y = fabs(1 / rays->dir.y);
	if (rays->dir.x < 0)
	{
		rays->step.x = -1;
		rays->side_dist.x = (data->hero.x - rays->map.x) * rays->delta.x;
	}
	else
	{
		rays->step.x = 1;
		rays->side_dist.x = (rays->map.x + 1.0 - data->hero.x) * rays->delta.x;
	}
	if (rays->dir.y < 0)
	{
		rays->step.y = -1;
		rays->side_dist.y = (data->hero.y - rays->map.y) * rays->delta.y;
	}
	else
	{
		rays->step.y = 1;
		rays->side_dist.y = (rays->map.y + 1.0 - data->hero.y) * rays->delta.y;
	}
}

static void	dda_algo(t_data *data, t_rays *rays)
{
	while (1)
	{
		if (rays->side_dist.x < rays->side_dist.y)
		{
			rays->side_dist.x += rays->delta.x;
			rays->map.x += rays->step.x;
			rays->side_hit = 0;
		}
		else
		{
			rays->side_dist.y += rays->delta.y;
			rays->map.y += rays->step.y;
			rays->side_hit = 1;
		}
		if (data->map[rays->map.y][rays->map.x] != '0')
			break ;
	}
}

static void	get_crutial_val(t_data *data, t_rays *rays)
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
	wall_hit_x_db -= floor(wall_hit_x_db);
// get the correct texture and cal
	rays->wall_hit_x = (wall_hit_x_db * 100);//100 -> texture width
	if ((rays->side_hit == 0 && rays->dir.x > 0) || (rays->side_hit == 1 && rays->dir.y < 0))
		rays->wall_hit_x = 100 - wall_hit_x_db - 1;
}

static void	ray_cast(t_data *data, t_rays *rays, int x)
{
	double	ray_angle;

	ray_angle = data->face_ang - FOV + x * rays->step_ang;
	rays->dir.x = cos(ray_angle) + 1e-6;
	rays->dir.y = -1 * sin(ray_angle) + 1e-6;
	ray_cast_init(data, rays);
	dda_algo(data, rays);
	get_crutial_val(data, rays);
	rays->perp_dist *= cos(ray_angle - data->face_ang);
	rays->wall_h = (int)(HEIGHT / rays->perp_dist);
	if (rays->wall_h < 1)
		rays->wall_h = 1;
	if (rays->wall_h > HEIGHT)
		rays->wall_h = HEIGHT;
}

void	draw_rc(t_data *data)
{
	int		x;
	t_rays	rays;

	ft_memset(&rays, 0, sizeof(rays));
	rays.step_ang = FOV * 2 / WIDTH;
	x = 0;
	while (x < WIDTH)
	{
		ray_cast(data, &rays, x);
		img_draw_wall(&data->rc, (t_cor_int){x, (HEIGHT - rays.wall_h) / 2},
			(t_cor_int){rays.wall_hit_x, (HEIGHT + rays.wall_h) / 2}, NORTH);
		x++;
	}
}
