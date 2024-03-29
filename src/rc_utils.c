/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:44:00 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/19 16:56:20 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

void	img_draw_pixel(t_draw *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	end_program(t_data *rc)
{
	(void)rc;
	exit(0);
	return (0);
}

int	key_press(int key, t_data *data)
{
	if (key == 53)
		end_program(data);
	if (key == 13)
		data->key.w = true;
	else if (key == 0)
		data->key.a = true;
	else if (key == 1)
		data->key.s = true;
	else if (key == 2)
		data->key.d = true;
	else if (key == 123)
		data->key.l = true;
	else if (key == 124)
		data->key.r = true;
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == 13)
		data->key.w = false;
	else if (key == 0)
		data->key.a = false;
	else if (key == 1)
		data->key.s = false;
	else if (key == 2)
		data->key.d = false;
	else if (key == 123)
		data->key.l = false;
	else if (key == 124)
		data->key.r = false;
	return (0);
}

void	put_imgs(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->rc.img, 0, 0);
}
