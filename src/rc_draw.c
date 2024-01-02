/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:51:49 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/02 16:06:57 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

void	img_draw_unit(
	t_draw *target, int unit_size, t_cor_int pos, unsigned int color)
{
	t_cor_int	del;

	del.y = 0;
	while (del.y < unit_size)
	{
		del.x = 0;
		while (del.x < unit_size)
		{
			img_draw_pixel(target, pos.x + del.x, pos.y + del.y, color);
			del.x++;
		}
		del.y++;
	}
}

// void	img_draw_line(
// 	t_draw *target, t_cor_int cur, t_cor_int end, unsigned int color)
// {
// 	int dx = abs(end.x - cur.x), sx = cur.x < end.x ? 1 : -1;
// 	int dy = -abs(end.y - cur.y), sy = cur.y < end.y ? 1 : -1;
// 	int err = dx + dy, e2; /* error value e_xy */
// 	while (1)
// 	{
// 		img_draw_unit(target, 2, cur, color);
// 		if (cur.x == end.x && cur.y == end.y) break;
// 		e2 = 2 * err;
// 		if (e2 >= dy) { err += dy; cur.x += sx; } /* e_xy+e_x > 0 */
// 		if (e2 <= dx) { err += dx; cur.y += sy; } /* e_xy+e_y < 0 */
// 	}
// }

void	img_draw_background(t_data *data)
{
	t_cor_int	pos;

	ft_memset(&pos, 0, sizeof(pos));
	while (pos.y < HEIGHT)
	{
		pos.x = 0;
		while (pos.x < WIDTH)
		{
			if (pos.y <= HEIGHT / 2)
				img_draw_pixel(&data->rc, pos.x, pos.y, data->texture.ceiling);
			else
				img_draw_pixel(&data->rc, pos.x, pos.y, data->texture.floor);
			pos.x++;
		}
		pos.y++;
	}
}

void	img_draw_wall(
	t_draw *target, t_cor_int pos, t_cor_int end, t_image wall)
{
	unsigned int	color;
	int				d;
	int				tex_y;
	int				line_h;

	line_h = end.y - pos.y;
	while (pos.y < end.y)
	{
		d = pos.y * 256 - HEIGHT * 128 + line_h * 128;
		tex_y = ((d * wall.width) / line_h) / 256;
		color = wall.addr[wall.width * tex_y + end.x];
		img_draw_pixel(target, pos.x, pos.y, color);
		pos.y++;
	}
}
