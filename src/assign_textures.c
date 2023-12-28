/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:43:57 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/28 17:01:59 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

/*
The function textures_assigned checks if all the textures are assigned.
Function used in the function create_textures in file assign_data.c.
*/

bool	textures_assigned(t_data *data)
{
	if (NORTH.addr != NULL && SOUTH.addr != NULL
		&& WEST.addr != NULL && EAST.addr != NULL
		&& data->texture.floor != -1 && data->texture.ceiling != -1)
		return (true);
	return (false);
}

/*
The function counts the number of strings in the line.
*/

static size_t	len_variables(char **variables)
{
	size_t	len;

	len = 0;
	while (variables[len])
		len++;
	return (len);
}

/*
The function check_valid_variables checks if the variables are valid.
First it checks if the number of variables is valid.
Then it checks if the variables are printable.
*/

static bool	check_valid_variables(char **tab)
{
	int	i_var;
	int	i_char;

	i_var = 0;
	if (len_variables(tab) > 2)
	{
		if (ft_strncmp(tab[2], "\n", 2) != 0)
			return (false);
	}
	while (tab[i_var])
	{
		i_char = 0;
		while (tab[i_var][i_char])
		{
			if (tab[i_var][i_char] == '\n' && tab[i_var][i_char + 1] == '\0')
				break ;
			if (!ft_isprint(tab[i_var][i_char]))
				return (false);
			i_char++;
		}
		i_var++;
	}
	return (true);
}

/*
The function assign_walls assign the walls to the data structure.
If the line ends with a '\n' the function removes it.
*/

static void	assign_walls(t_draw *cardinal, char **tab)
{
	if (tab[1][ft_strlen(tab[1]) - 1] == '\n')
		cardinal->addr = ft_substr(tab[1], 0, ft_strlen(tab[1]) - 1);
	else
		cardinal->addr = ft_strdup(tab[1]);
}

/*
The function assign_textures assign the textures to the data structure.
*/

bool	assign_textures(t_data *data, char **tab)
{
	if (check_valid_variables(tab) == false)
		return (false);
	if (ft_strncmp(tab[0], "NO", 3) == 0 && NORTH.addr == NULL)
		assign_walls(&NORTH, tab);
	else if (ft_strncmp(tab[0], "SO", 3) == 0 && SOUTH.addr == NULL)
		assign_walls(&SOUTH, tab);
	else if (ft_strncmp(tab[0], "WE", 3) == 0 && WEST.addr == NULL)
		assign_walls(&WEST, tab);
	else if (ft_strncmp(tab[0], "EA", 3) == 0 && EAST.addr == NULL)
		assign_walls(&EAST, tab);
	else if (ft_strncmp(tab[0], "F", 2) == 0 && data->texture.floor == -1)
		data->texture.floor = 0;
	else if (ft_strncmp(tab[0], "C", 2) == 0 && data->texture.ceiling == -1)
		data->texture.ceiling = 0;
	else if (ft_strncmp(tab[0], "\n", 2) != 0)
		return (false);
	return (true);
}
