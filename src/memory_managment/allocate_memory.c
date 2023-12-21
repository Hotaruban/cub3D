/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 05:58:14 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/21 17:26:03 by jhurpy           ###   ########.fr       */
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
	texture->floor = -1;
	texture->ceiling = -1;
	return (texture);
}

/*
The function allocate_memory allocates memory for the structure t_data.
*/

t_data	*allocate_memory(t_data *data)
{
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		msg_error_exit(NULL, "Memory allocation failed!\n");
	data->texture = allocate_memory_texture(data->texture);
	if (!data->texture)
		msg_error_exit(data, "Memory allocation failed!\n");
	return (data);
}
