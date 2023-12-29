/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:32:18 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/30 03:09:33 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_cub3d.h"

void	print_map(t_data *data, FILE *p_fd)
{
	int		i;

	i = 0;
	fprintf(p_fd, "\n--- START of data->map ---\n");
	if (data->map)
	{
		while (data->map[i])
		{
			fprintf(p_fd, "data->map[%d] = %s\n", i, data->map[i]);
			i++;
		}
	}
	else
		fprintf(p_fd, "data->map = NULL\n");
	fprintf(p_fd, "data->face_dir = %c\n", data->face_dir);
	fprintf(p_fd, "data->hero.pos.x = %f\n", data->hero.x);
	fprintf(p_fd, "data->hero.pos.y = %f\n", data->hero.y);
	fprintf(p_fd, "--- END of data->map ---\n");
}

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
		print_map(data, p_fd);
	}
}

void	print_list(t_list *list)
{
	int		i;

	i = 0;
	while (list != NULL)
	{
		printf("line [%d] => %s\n", i, (char *)list->content);
		list = list->next;
		i++;
	}
}
