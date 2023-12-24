/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:56:15 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/24 17:47:12 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_cub3d.h"

/*
The function check_extension take a path and check if the extension is correct.
*/

bool	check_extension(char *path, char *ext)
{
	int	len_ext;
	int	len_path;

	len_ext = ft_strlen(ext);
	len_path = ft_strlen(path);
	if (len_ext > len_path)
		return (false);
	if (ft_strncmp(&path[len_path - len_ext], ext, len_ext + 1) != 0)
		return (false);
	return (true);
}

/*
The function check_access_file take a path and check if the file exist and
is accessible.
*/

bool	check_access_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
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
The function checks if the variables are printable characters.
*/

bool	check_valid_variables(char **variables)
{
	int	index_var;
	int	index_char;

	index_var = 0;
	if (len_variables(variables) > 2)
	{
		free_2d_array(variables);
		return (false);
	}
	while (variables[index_var])
	{
		index_char = 0;
		while (variables[index_var][index_char])
		{
			if (variables[index_var][index_char] == '\n'
				&& variables[index_var][index_char + 1] == '\0')
				break ;
			if (!ft_isprint(variables[index_var][index_char]))
			{
				free_2d_array(variables);
				return (false);
			}
			index_char++;
		}
		index_var++;
	}
	return (true);
}
