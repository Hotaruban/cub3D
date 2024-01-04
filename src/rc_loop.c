/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:49:41 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/04 19:36:06 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

int	data_loop(t_data *data)
{
	move_hero(data);
	img_draw_background(data);
	draw_rc(data);
	// draw_minimap(data);
	put_imgs(data);
	return (0);
}
