/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:38:18 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/02 16:26:43 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

static void	data_malloc(t_data *data)
{
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "data3D");
	if (!data->win)
	{
		ft_putstr_fd("Fail to construct window.\n", 2);
		exit(1);
	}
	init_draw(data->mlx, &data->mini_map, 100, 100);
	if (!data->mini_map.img)
	{
		ft_putstr_fd("Fail to construct minimap image.\n", 2);
		exit(1);
	}
	init_draw(data->mlx, &data->rc, WIDTH, HEIGHT);
	if (!data->mini_map.img)
	{
		ft_putstr_fd("Fail to construct ray-casting image.\n", 2);
		exit(1);
	}
}

void	data_init(t_data *data)
{
	data_malloc(data);
	data->face_ang = PI / 2;
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
