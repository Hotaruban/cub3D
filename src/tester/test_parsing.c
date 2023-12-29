/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:32:18 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/29 23:34:07 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_cub3d.h"

void	test_parsing(t_data *data, char *str)
{
	FILE	*p_fd;

	p_fd = fopen("./src/tester/.test_return", "w");
	if (data)
{
		fprintf(p_fd, "\n--- START of data->texture %s ---\n", str);
		fprintf(p_fd, "\tdata->texture->north = %s<-\n", data->texture.north.addr);
		fprintf(p_fd, "\tdata->texture->south = %s<-\n", data->texture.south.addr);
		fprintf(p_fd, "\tdata->texture->west = %s<-\n", data->texture.west.addr);
		fprintf(p_fd, "\tdata->texture->east = %s<-\n", data->texture.east.addr);
		fprintf(p_fd, "\tdata->texture->floor = %d\n", data->texture.floor);
		fprintf(p_fd, "\tdata->texture->ceiling = %d\n", data->texture.ceiling);
		fprintf(p_fd, "--- END of data->texture ---\n");
	}
}
