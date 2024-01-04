/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:24:48 by jhurpy            #+#    #+#             */
/*   Updated: 2024/01/05 01:19:31 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

bool	check_in_square(char **map, int y, int x)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	j = -1;
	flag = 0;
	while (i < 2 && (map[y + i][x + j] == '1'
		|| map[y + i][x + j] == '0'))
	{
		while (j < 2 && (map[y + i][x + j] == '1'
			|| map[y + i][x + j] == '0'))
		{
			printf("map Y[%d]X[%d] = %c\n", y + i, x + j, map[y + i][x + j]);
			flag++;
			j++;
		}
		j = -1;
		i++;
	}
	if (flag == 9)
		return (true);
	return (false);
}

//static void	flood_fill()
//{

//}

//static bool	check_map_correct(char **map)
//{
//	int	i;
//	int	j;

//	i = 0;
//	while (map[i] != NULL)
//	{
//		j = 0;
//		while (map[i][j] != '\0')
//		{
//			if (map[i][j] != '1' && map[i][j] != '2')
//				return (false);
//			j++;
//		}
//		i++;
//	}
//	return (true);
//}

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
	return (true);
}
