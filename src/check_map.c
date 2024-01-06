/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:24:48 by jhurpy            #+#    #+#             */
/*   Updated: 2024/01/06 19:26:04 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

/*
The function find_location returns the y position of the character c.
*/

static int	find_location(char **map, char c)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == c)
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

static char	**copy_map(int len_map, char **map)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = (char **)malloc(sizeof(char *) * (len_map + 1));
	if (!map_copy)
		return (NULL);
	while (i < len_map)
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

static void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == '2')
		return ;
	if (map[y][x] == '0')
		map[y][x] = '2';
	if (map[y][x + 1] != '\0')
		flood_fill(map, y, x + 1);
	if (map[y][x - 1] != '\0')
		flood_fill(map, y, x - 1);
	if (map[y + 1][x] != '\0')
		flood_fill(map, y + 1, x);
	if (map[y - 1][x] != '\0')
		flood_fill(map, y - 1, x);
}

static bool	check_map_correct(t_data *data, char **map)
{
	int		i;
	int		j;
	char	**map_copy;

	i = 0;
	map_copy = copy_map(data->map_height, map);
	if (!map_copy)
		return (msg_error(MEM_ALLOC_FAILED), false);
	flood_fill(map_copy, 1, find_location(map_copy, '0'));
	while (i < data->map_height)
	{
		j = 0;
		while (map_copy[i][j] != '\0')
		{
			if (map_copy[i][j] != '1' && map_copy[i][j] != '2'
				&& map_copy[i][j] != ' ')
			{
				free_tab(map_copy);
				return (msg_error(MAP_INVALID), false);
			}
			j++;
		}
		i++;
	}
	return (free_tab(map_copy), true);
}

bool	check_valid_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == '0')
			{
				if (check_in_square(data->map, y, x) == false)
					return (msg_error(MAP_INVALID), false);
			}
			x++;
		}
		y++;
	}
	if (check_map_correct(data, data->map) == false)
	{
		return (false);
	}
	return (true);
}
