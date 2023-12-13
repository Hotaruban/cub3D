/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:55:38 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/14 01:13:52 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_cub3d.h"

static bool	check_texture_complete(t_texture *texture)
{
	if (texture->north == NULL || texture->south == NULL
		|| texture->west == NULL || texture->east == NULL
		|| texture->floor == NULL || texture->ceiling == NULL)
		return (false);
	return (true);
}

static bool	check_texture(t_texture *texture, char *line, int *index)
{
	if (ft_strncmp(line + *index, "NO ", 3) == 0)
		texture->north = parse_string(line, index);
	else if (ft_strncmp(line + *index, "SO ", 3) == 0)
		texture->south = parse_string(line, index);
	else if (ft_strncmp(line + *index, "WE ", 3) == 0)
		texture->west = parse_string(line, index);
	else if (ft_strncmp(line + *index, "EA ", 3) == 0)
		texture->east = parse_string(line, index);
	else if (ft_strncmp(line + *index, "F ", 2) == 0)
		texture->floor = parse_string(line, index);
	else if (ft_strncmp(line + *index, "C ", 2) == 0)
		texture->ceiling = parse_string(line, index);
	else if (line[*index] != '\n')
		return (false);
	return (true);
}

bool	init_textures(int fd, t_texture *texture)
{
	char	*line;
	int		*index;

	line = get_next_line(fd);
	while (check_texture_complete(texture) == false && line != NULL)
	{
		index = 0;
		free(line);
		line = get_next_line(fd);
		parse_space(line, index);
		if (check_texture(texture, line, index) == false)
		{
			free(line);
			return (false);
		}
	}
	return (true);
}
