/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:39:25 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/02 15:59:54 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

void	move_hero(t_data *data)
{
	if (data->key.w)
		if (data->map[(int)(data->hero.y - 0.04)][(int)data->hero.x] == '0')
			data->hero.y -= 0.02;
	if (data->key.a)
		if (data->map[(int)data->hero.y][(int)(data->hero.x - 0.04)] == '0')
			data->hero.x -= 0.02;
	if (data->key.s)
		if (data->map[(int)(data->hero.y + 0.04)][(int)data->hero.x] == '0')
			data->hero.y += 0.02;
	if (data->key.d)
		if (data->map[(int)data->hero.y][(int)(data->hero.x + 0.04)] == '0')
			data->hero.x += 0.02;
	if (data->key.r)
		data->face_ang += 0.02;
	if (data->key.l)
		data->face_ang -= 0.02;
	if (data->face_ang >= 2 * PI)
		data->face_ang -= 2 * PI;
	else if (data->face_ang <= 0)
		data->face_ang += 2 * PI;
}
