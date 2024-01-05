/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 03:13:35 by jhurpy            #+#    #+#             */
/*   Updated: 2024/01/05 13:44:12 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

/*
The function check_in_square checks if the position (y, x) is surrounded by
walls (1) or empty spaces (0).
*/

bool	check_in_square(char **map, int y, int x)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	j = -1;
	flag = 0;
	if (y == 0 || x == 0 || !map[y + 1] || !map[y][x + 1])
		return (false);
	while (i < 2 && (map[y + i][x + j] == '1'
		|| map[y + i][x + j] == '0'))
	{
		while (j < 2 && (map[y + i][x + j] == '1'
			|| map[y + i][x + j] == '0'))
		{
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
