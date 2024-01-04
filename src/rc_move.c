/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:39:25 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/04 23:07:13 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

void static	move(t_data *data, double angle)
{
	t_cor_db	dir;

	dir.x = cos(angle);
	dir.y = -1 * sin(angle);
	if (data->map[(int)(data->hero.y + dir.y * SPEED)]
		[(int)(data->hero.x + dir.x * SPEED)] == '0')
	{
		data->hero.x += dir.x * SPEED / 2;
		data->hero.y += dir.y * SPEED / 2;
	}
	else if (data->map[(int)(data->hero.y)]
		[(int)(data->hero.x + dir.x * SPEED)] == '0')
		data->hero.x += dir.x * SPEED / 2;
	else if (data->map[(int)(data->hero.y + dir.y * SPEED)]
		[(int)(data->hero.x)] == '0')
		data->hero.y += dir.y * SPEED / 2;
}

void	move_hero(t_data *data)
{
	if (data->key.w)
		move(data, data->face_ang);
	if (data->key.a)
		move(data, data->face_ang - PI / 2);
	if (data->key.s)
		move(data, data->face_ang + PI);
	if (data->key.d)
		move(data, data->face_ang + PI / 2);
	if (data->key.r)
		data->face_ang += 0.02;
	if (data->key.l)
		data->face_ang -= 0.02;
	if (data->face_ang >= 2 * PI)
		data->face_ang -= 2 * PI;
	else if (data->face_ang <= 0)
		data->face_ang += 2 * PI;
}
