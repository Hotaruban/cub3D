/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:44:00 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/04 23:11:16 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

void	init_image(t_image *img)
{
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
}
