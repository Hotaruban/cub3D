/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:32:18 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/24 16:17:44 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_cub3d.h"

void	test_parsing(t_data *data, char *str)
{
	FILE	*p_fd;

	p_fd = fopen("./src/tester/.test_return", "a");
	if (data)
	{
		if (data->texture)
		{
			fprintf(p_fd, "\n--- START of data->texture %s ---\n", str);
			if (data->texture->north)
				fprintf(p_fd, "\tdata->texture->north = %s<-\n", data->texture->north);
			if (data->texture->south)
				fprintf(p_fd, "\tdata->texture->south = %s<-\n", data->texture->south);
			if (data->texture->west)
				fprintf(p_fd, "\tdata->texture->west = %s<-\n", data->texture->west);
			if (data->texture->east)
				fprintf(p_fd, "\tdata->texture->east = %s<-\n", data->texture->east);
			fprintf(p_fd, "\tdata->texture->floor = %d\n", data->texture->floor);
			fprintf(p_fd, "\tdata->texture->ceiling = %d\n", data->texture->ceiling);
			fprintf(p_fd, "--- END of data->texture ---\n");
		}
	}
}
