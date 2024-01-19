/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:43:57 by jhurpy            #+#    #+#             */
/*   Updated: 2024/01/19 18:27:32 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

/*
The function check_color checks if the color is valid.
*/

static bool	check_color(char **tab_rgb)
{
	int	i;

	i = 0;
	if (len_variables(tab_rgb) != 3)
		return (false);
	while (tab_rgb[i])
	{
		if (ft_strlen(tab_rgb[i]) > 3)
			return (false);
		i++;
	}
	if (check_valid_digit(tab_rgb[0]) == false
		|| check_valid_digit(tab_rgb[1]) == false
		|| check_valid_digit(tab_rgb[2]) == false)
		return (false);
	if ((ft_atoi(tab_rgb[0]) < 0 && ft_atoi(tab_rgb[0]) > 255)
		|| (ft_atoi(tab_rgb[1]) < 0 && ft_atoi(tab_rgb[1]) > 255)
		|| (ft_atoi(tab_rgb[2]) < 0 && ft_atoi(tab_rgb[2]) > 255))
		return (false);
	return (true);
}

/*
The function assign_color assign the color to the data structure.
*/

static void	assign_color(int *color, char *rgb_str)
{
	char	**tab_rgb;
	char	*tmp;

	tmp = NULL;
	assign_variable(&tmp, rgb_str);
	tab_rgb = ft_split(tmp, ',');
	if (check_color(tab_rgb) == false)
		*color = -2;
	else
		*color = (ft_atoi(tab_rgb[0]) * 256 * 256
				+ ft_atoi(tab_rgb[1]) * 256 + ft_atoi(tab_rgb[2]));
	free_tab(tab_rgb);
	free(tmp);
}

/*
The function check_valid_variables checks if the variables are valid.
First it checks if the number of variables is valid.
Then it checks if the variables are printable.
*/

static void	check_valid_variables(char **tab)
{
	int	i_var;
	int	i_char;

	i_var = 0;
	if (len_variables(tab) > 2)
	{
		if (ft_strncmp(tab[2], "\n", 2) != 0)
			msg_error(TEXTURE_INVALID);
	}
	while (tab[i_var])
	{
		i_char = 0;
		while (tab[i_var][i_char])
		{
			if (tab[i_var][i_char] == '\n' && tab[i_var][i_char + 1] == '\0')
				break ;
			if (!ft_isprint(tab[i_var][i_char]))
				msg_error(TEXTURE_INVALID);
			i_char++;
		}
		i_var++;
	}
}

/*
The function assign_textures assign the textures to the data structure.
*/

void	assign_textures(t_data *data, char **tab)
{
	check_valid_variables(tab);
	if (ft_strncmp(tab[0], "NO", 3) == 0 && NORTH.addr == NULL)
		assign_variable(&(NORTH.addr), tab[1]);
	else if (ft_strncmp(tab[0], "SO", 3) == 0 && SOUTH.addr == NULL)
		assign_variable(&(SOUTH.addr), tab[1]);
	else if (ft_strncmp(tab[0], "WE", 3) == 0 && WEST.addr == NULL)
		assign_variable(&(WEST.addr), tab[1]);
	else if (ft_strncmp(tab[0], "EA", 3) == 0 && EAST.addr == NULL)
		assign_variable(&(EAST.addr), tab[1]);
	else if (ft_strncmp(tab[0], "F", 2) == 0 && data->texture.floor == -1)
		assign_color(&(data->texture.floor), tab[1]);
	else if (ft_strncmp(tab[0], "C", 2) == 0 && data->texture.ceiling == -1)
		assign_color(&(data->texture.ceiling), tab[1]);
	else if (ft_strncmp(tab[0], "\n", 2) != 0)
		msg_error(TEXTURE_INVALID);
}
