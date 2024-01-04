/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:38:18 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/04 21:53:07 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

// are you sure you want to exit if failed ? We should free memory before no ?

static void	data_malloc(t_data *data)
{
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "data3D");
	if (!data->win)
	{
		msg_error(FAIL_WINDOW);
		exit(EXIT_FAILURE);
	}
	init_draw(data->mlx, &data->mini_map, 100, 100);
	if (!data->mini_map.img)
	{
		msg_error(FAIL_MINIMAP);
		exit(EXIT_FAILURE);
	}
	init_draw(data->mlx, &data->rc, WIDTH, HEIGHT);
	if (!data->mini_map.img)
	{
		msg_error(FAIL_RAYCASTING);
		exit(EXIT_FAILURE);
	}
}

void	data_init(t_data *data)
{
	data_malloc(data);
	//data->face_ang = PI / 2;
	mlx_hook(data->win, ON_DESTROY, 0, end_program, data);
}

void	init_draw(void *mlx, t_draw *tar, int width, int height)
{
	tar->img = mlx_new_image(mlx, width, height);
	if (!tar->img)
		return ;
	tar->addr = mlx_get_data_addr(
			tar->img, &tar->bits_per_pixel,
			&tar->line_length, &tar->endian);
	// no need, for test
	tar->tex_h = height;
	tar->tex_w = width;
	//
}
