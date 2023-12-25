/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 23:30:35 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/25 14:16:12 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_cub3d.h"

/*
The function free_2d_array free a 2d array.
*/

void	free_2d_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

/*
The free_texture function free the texture structure.
*/

static void	free_texture(t_texture *texture)
{
		if (texture->north)
			free(texture->north);
		if (texture->south)
			free(texture->south);
		if (texture->west)
			free(texture->west);
		if (texture->east)
			free(texture->east);
		free(texture);
}

/*
The free_data function free the data structure.
*/

void	free_data(t_data *data)
{
	if (data->texture)
		free_texture(data->texture);
	free(data);
}
