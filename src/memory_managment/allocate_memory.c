/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 05:58:14 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/25 13:52:04 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_cub3d.h"

/*
The function init_texture initialize the texture structure.
*/

static bool init_texture(t_texture *texture)
{
	texture = (t_texture *)malloc(sizeof(t_texture));
	if (texture == NULL)
		return (NULL);
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	texture->east = NULL;
	texture->floor = -1;
	texture->ceiling = -1;
	return (texture);
}

/*
The function alloc_mem_init allocate memory for the data structure and
initialize the texture structure.
*/

bool	alloc_mem_init(t_data *data)
{
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
	{
		msg_error(MEMORY_ALLOCATION);
		return (false);
	}
	if (init_texture(data->texture) == false)
	{
		free_data(data);
		msg_error(MEMORY_ALLOCATION);
		return (false);
	}
	return (data);
}
