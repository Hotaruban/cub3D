/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:49:41 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/04 23:12:08 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

	/* draw_minimap(data); */
int	data_loop(t_data *data)
{
	move_hero(data);
	img_draw_background(data);
	draw_rc(data);
	put_imgs(data);
	return (0);
}
