/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:55:38 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/21 16:18:22 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_cub3d.h"

/*
The function check_texture_complete check if all the textures are initialized.
*/

static bool	check_texture_complete(t_texture *texture)
{
	if (texture->north != NULL && texture->south != NULL
		&& texture->west != NULL && texture->east != NULL
		&& texture->floor_color != -1 && texture->ceiling_color != -1)
		return (true);
	return (false);
}

/*
The function check_texture take the second argument of the line and save it
in the correct variable.
*/

static bool	check_texture(t_texture *texture, char **line)
{
	if (ft_strncmp(line[0], "NO", 3) == 0)
		texture->north = line[1];
	else if (ft_strncmp(line[0], "SO", 3) == 0)
		texture->south = line[1];
	else if (ft_strncmp(line[0], "WE", 3) == 0)
		texture->west = line[1];
	else if (ft_strncmp(line[0], "EA", 3) == 0)
		texture->east = line[1];
	else if (ft_strncmp(line[0], "F", 2) == 0)
		texture->floor_color = /*function to turn floor color string in number*/0;
	else if (ft_strncmp(line[0], "C", 2) == 0)
		texture->ceiling_color = /*function to turn ceiling color string in number*/0;
	else if (ft_strncmp(line[0], "\n", 2) != 0)
		return (false);
	return (true);
}

/*
The function split_line check if the line is correctly formated.
*/

static bool	split_line(char *line, t_texture *texture)
{
	char	**line_split;

	line_split = ft_split(line, ' ');
	if (line_split == NULL)
		return (false);
	if (line_split[2] != NULL)
		return (false);
	if (check_texture(texture, line_split) == false)
		return (false);
	return (true);
}

/*
The function init_textures parse the map and initialize the textures if the
information are correct.
*/

bool	init_textures(int fd, t_texture *texture)
{
	char	*line;

	while (check_texture_complete(texture) == false)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (false);
		if (split_line(line, texture) == false)
			return (false);
	}
	return (true);
}
