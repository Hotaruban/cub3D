/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:32:18 by jhurpy            #+#    #+#             */
/*   Updated: 2024/01/02 19:32:11 by jhurpy           ###   ########.fr       */
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
			fprintf(p_fd, "\tdata->map[%d] \t= \t%s<-\n", i, data->map[i]);
			i++;
		}
	}
	else
		fprintf(p_fd, "data->map = NULL\n");
	fprintf(p_fd, "\tdata->face_ang = \t%f<-\n", data->face_ang);
	fprintf(p_fd, "\tdata->hero.pos.x = \t%f<-\n", data->hero.x);
	fprintf(p_fd, "\tdata->hero.pos.y = \t%f<-\n", data->hero.y);
	fprintf(p_fd, "--- END of data->map ---\n");
}

static void	print_img(FILE *p_fd, t_image *img)
{
	fprintf(p_fd, "\timg = \t\t%p<-\n", img->img);
	fprintf(p_fd, "\taddr = \t\t%s<-\n", img->addr);
	fprintf(p_fd, "\twidth = \t%d<-\n", img->width);
	fprintf(p_fd, "\theight = \t%d<-\n", img->height);
}

static void	print_img_data(t_data *data, FILE *p_fd)
{
	fprintf(p_fd, "\n--- START of Image ---\n");
	fprintf(p_fd, "--- NORTH ---\n");
	print_img(p_fd, &NORTH);
	fprintf(p_fd, "--- SOUTH ---\n");
	print_img(p_fd, &SOUTH);
	fprintf(p_fd, "--- WEST ---\n");
	print_img(p_fd, &WEST);
	fprintf(p_fd, "--- EAST ---\n");
	print_img(p_fd, &EAST);
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
