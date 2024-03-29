/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:38:18 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/27 18:40:41 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

static void	data_malloc(t_data *data)
{
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3D");
	if (!data->win)
	{
		msg_error(FAIL_WINDOW);
		exit(EXIT_FAILURE);
	}
	init_draw(data->mlx, &data->rc, WIDTH, HEIGHT);
	if (!data->rc.img)
	{
		msg_error(FAIL_RAYCASTING);
		exit(EXIT_FAILURE);
	}
}

void	data_init(t_data *data)
{
	data_malloc(data);
	mlx_hook(data->win, ON_DESTROY, 0, end_program, data);
	data->hero.y += 0.49;
	data->hero.x += 0.49;
}

void	init_draw(void *mlx, t_draw *tar, int width, int height)
{
	tar->img = mlx_new_image(mlx, width, height);
	if (!tar->img)
		return ;
	tar->addr = mlx_get_data_addr(
			tar->img, &tar->bits_per_pixel,
			&tar->line_length, &tar->endian);
	tar->tex_h = height;
	tar->tex_w = width;
}
