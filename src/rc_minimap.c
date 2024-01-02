/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:20:25 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/02 16:29:11 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

static void	draw_blocks(t_data *data)
{
	unsigned int	white;
	unsigned int	transp;
	t_cor_int		cur_pos;

	white = mlx_get_color_value(data->mlx, 0x7fffffff);
	transp = mlx_get_color_value(data->mlx, 0xff000000);
	cur_pos.y = 0;
	while (cur_pos.y < 5)
	{
		cur_pos.x = 0;
		while (cur_pos.x < 5)
		{
			if (data->map[cur_pos.y][cur_pos.x] == '1')
				img_draw_unit(&data->mini_map, 20,
					(t_cor_int){cur_pos.x * 20, cur_pos.y * 20}, white);
			else
				img_draw_unit(&data->mini_map, 20,
					(t_cor_int){cur_pos.x * 20, cur_pos.y * 20}, transp);
			cur_pos.x++;
		}
		cur_pos.y++;
	}
}

static void	draw_hero(t_data *data)
{
	unsigned int	red;

	red = mlx_get_color_value(data->mlx, 0x7fff0000);
	img_draw_unit(&data->mini_map, 10,
		(t_cor_int){data->hero.x * 20, data->hero.y * 20}, red);
}

// static	void	draw_view_line(t_data *data, double dir_x, double dir_y)
// {
// 	t_cor_db	end;

// 	end.x = data->hero.x;
// 	end.y = data->hero.y;
// 	while (data->map[(int)end.y][(int)end.x] == '0')
// 	{
// 		end.x += dir_x;
// 		end.y += dir_y;
// 	}
// 	img_draw_line(&data->mini_map,
// 		(t_cor_int){data->hero.x * 20 + 4, data->hero.y * 20 + 4},
// 		(t_cor_int){end.x * 20, end.y * 20}, data->texture.ceiling);
// }

void	draw_minimap(t_data *data)
{
	// unsigned int	char_color;

	// char_color = mlx_get_color_value(data->mlx, 0xff0000);
	draw_blocks(data);
	draw_hero(data);
	// draw_view_line(data, cos(data->face_ang + FOV), sin(data->face_ang + FOV));
	// draw_view_line(data, cos(data->face_ang - FOV), sin(data->face_ang - FOV));
}
