/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:29:19 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/19 16:36:15 by ychen2           ###   ########.fr       */
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

static void	ray_cast(t_data *data, t_rays *rays, int x)
{
	double	ray_angle;

	ray_angle = data->face_ang - FOV + x * rays->step_ang;
	rays->dir.x = -1 * cos(ray_angle);
	rays->dir.y = -1 * sin(ray_angle);
	ray_cast_init(data, rays);
	dda_algo(data, rays);
	get_crutial_val(data, rays);
	rays->perp_dist *= cos(ray_angle - data->face_ang);
	rays->wall_h = (int)(HEIGHT / rays->perp_dist);
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
			(t_cor_int){rays.wall_hit_x,
			(HEIGHT + rays.wall_h) / 2}, rays.wall);
		x++;
	}
}
