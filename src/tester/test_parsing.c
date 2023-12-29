/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:32:18 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/30 05:28:30 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_cub3d.h"

/*
The following function is used to print the map.
*/

void	print_map(t_data *data, FILE *p_fd)
{
	int		i;

	i = 0;
	fprintf(p_fd, "\n--- START of data->map ---\n");
	if (data->map)
	{
		while (data->map[i])
		{
			fprintf(p_fd, "\tdata->map[%d] = \t\t%s<-\n", i, data->map[i]);
			i++;
		}
	}
	else
		fprintf(p_fd, "data->map = NULL\n");
	fprintf(p_fd, "\tdata->face_dir = \t%c<-\n", data->face_dir);
	fprintf(p_fd, "\tdata->hero.pos.x = \t%f<-\n", data->hero.x);
	fprintf(p_fd, "\tdata->hero.pos.y = \t%f<-\n", data->hero.y);
	fprintf(p_fd, "--- END of data->map ---\n");
}

static void	print_img_data(t_data *data, FILE *p_fd)
{
	fprintf(p_fd, "\n--- START of Image ---\n");
	fprintf(p_fd, "--- NORTH ---\n");
	fprintf(p_fd, "\tdata->texture->north.img = \t%p<-\n", NORTH.img);
	fprintf(p_fd, "\tdata->texture->north.addr = \t%s<-\n", NORTH.addr);
	fprintf(p_fd, "\tdata->texture->north.bits_per_pixel = \t%d<-\n", NORTH.bits_per_pixel);
	fprintf(p_fd, "\tdata->texture->north.line_length = \t%d<-\n", NORTH.line_length);
	fprintf(p_fd, "\tdata->texture->north.endian = \t%d<-\n", NORTH.endian);
	fprintf(p_fd, "--- SOUTH ---\n");
	fprintf(p_fd, "\tdata->texture->south.img = \t%p<-\n", SOUTH.img);
	fprintf(p_fd, "\tdata->texture->south.addr = \t%s<-\n", SOUTH.addr);
	fprintf(p_fd, "\tdata->texture->south.bits_per_pixel = \t%d<-\n", SOUTH.bits_per_pixel);
	fprintf(p_fd, "\tdata->texture->south.line_length = \t%d<-\n", SOUTH.line_length);
	fprintf(p_fd, "\tdata->texture->south.endian = \t%d<-\n", SOUTH.endian);
	fprintf(p_fd, "--- WEST ---\n");
	fprintf(p_fd, "\tdata->texture->west.img = \t%p<-\n", WEST.img);
	fprintf(p_fd, "\tdata->texture->west.addr = \t%s<-\n", WEST.addr);
	fprintf(p_fd, "\tdata->texture->west.bits_per_pixel = \t%d<-\n", WEST.bits_per_pixel);
	fprintf(p_fd, "\tdata->texture->west.line_length = \t%d<-\n", WEST.line_length);
	fprintf(p_fd, "\tdata->texture->west.endian = \t%d<-\n", WEST.endian);
	fprintf(p_fd, "--- EAST ---\n");
	fprintf(p_fd, "\tdata->texture->east.img = \t%p<-\n", EAST.img);
	fprintf(p_fd, "\tdata->texture->east.addr = \t%s<-\n", EAST.addr);
	fprintf(p_fd, "\tdata->texture->east.bits_per_pixel = \t%d<-\n", EAST.bits_per_pixel);
	fprintf(p_fd, "\tdata->texture->east.line_length = \t%d<-\n", EAST.line_length);
	fprintf(p_fd, "\tdata->texture->east.endian = \t%d<-\n", EAST.endian);
	fprintf(p_fd, "--- END of Image ---\n");
}

/*
The following function is used to test the parsing of the map.
*/

void	test_parsing(t_data *data, char *str)
{
	FILE	*p_fd;

	p_fd = fopen("./src/tester/.test_return", "w");
	if (data)
	{
		fprintf(p_fd, "\n--- START of data->texture %s ---\n", str);
		fprintf(p_fd, "\tdata->texture->north = \t\t%s<-\n", data->texture.north.addr);
		fprintf(p_fd, "\tdata->texture->south = \t\t%s<-\n", data->texture.south.addr);
		fprintf(p_fd, "\tdata->texture->west = \t\t%s<-\n", data->texture.west.addr);
		fprintf(p_fd, "\tdata->texture->east = \t\t%s<-\n", data->texture.east.addr);
		fprintf(p_fd, "\tdata->texture->floor = \t\t%d<-\n", data->texture.floor);
		fprintf(p_fd, "\tdata->texture->ceiling = \t%d<-\n", data->texture.ceiling);
		fprintf(p_fd, "--- END of data->texture ---\n");
		print_map(data, p_fd);
		print_img_data(data, p_fd);
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
