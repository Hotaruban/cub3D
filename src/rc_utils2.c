/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:44:00 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/06 20:04:18 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

void	init_image(t_image *img)
{
	free(img->addr);
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
}
