/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:24:48 by jhurpy            #+#    #+#             */
/*   Updated: 2024/01/19 18:35:07 by jhurpy           ###   ########.fr       */
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

/*
The function copy_map copies the map in a new variable.
The map copied will be used to check if the map is valid.
*/

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

/*
The function flood_fill fills the map with the character '2'.
This function is used to check if the map is closed.
*/

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

/*
The function check_map_correct checks if the map is valid.
Check if the map is closed and if there is no character other than '1', '2'
*/

static void	check_map_correct(t_data *data, char **map)
{
	int		i;
	int		j;
	char	**map_copy;

	i = 0;
	map_copy = copy_map(data->map_height, map);
	if (!map_copy)
		msg_error(MEM_ALLOC_FAILED);
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
				msg_error(MAP_INVALID);
			}
			j++;
		}
		i++;
	}
	free_tab(map_copy);
}

/*
The function check_valid_map checks if the map is valid.
Check if the map is closed and if there is no character other than '1', '2'
Check if the the floor is closed by walls.
*/

void	check_valid_map(t_data *data)
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
				check_in_square(data->map, y, x);
				break ;
			}
			x++;
		}
		y++;
	}
	check_map_correct(data, data->map);
}
