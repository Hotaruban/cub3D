/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:51:49 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/19 16:56:45 by ychen2           ###   ########.fr       */
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

static int	get_pixel_color(t_draw *img, int x, int y)
{
	void	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(int *)dst);
}

void	img_draw_wall(
	t_draw *target, t_cor_int pos, t_cor_int end, t_draw wall)
{
	unsigned int	color;
	int				d;
	int				tex_y;
	int				line_h;

	line_h = end.y - pos.y;
	if (pos.y < 0)
		pos.y = 0;
	if (end.y >= HEIGHT)
		end.y = HEIGHT - 1;
	while (pos.y < end.y)
	{
		d = (pos.y - HEIGHT / 2 + line_h / 2) * wall.tex_h;
		tex_y = d / line_h;
		if (tex_y >= wall.tex_h)
			tex_y = wall.tex_h - 1;
		if (tex_y < 0)
			tex_y = 0;
		color = get_pixel_color(&wall, end.x, tex_y);
		img_draw_pixel(target, pos.x, pos.y, color);
		pos.y++;
	}
}
