/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 05:58:14 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/21 16:19:41 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_cub3d.h"

/*
The function allocate_memory_texture allocates memory
for the structure t_texture.
*/

static t_texture *allocate_memory_texture(t_texture *texture)
{
	texture = (t_texture *)malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	texture->east = NULL;
	texture->floor_color = -1;
	texture->ceiling_color = -1;
	return (texture);
}

/*
The function allocate_memory allocates memory for the structure t_data.
*/

t_data	*allocate_memory(t_data *data)
{
	t_data	*new_data;

	new_data = (t_data *)malloc(sizeof(t_data));
	if (!new_data)
		return (NULL);
	new_data->texture = allocate_memory_texture(data->texture);
	return (new_data);
}
