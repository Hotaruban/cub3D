/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:56:15 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/30 03:01:30 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

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
The function assign_variable assign the variable with the string str.
If the string str end with '\n' the function assign_variable remove the '\n'.
*/

void	assign_variable(char **var, char *str)
{
	if (str[ft_strlen(str) - 1] == '\n')
		*var = ft_substr(str, 0, ft_strlen(str) - 1);
	else
		*var = ft_strdup(str);
}

/*
The function counts the number of strings in the line.
*/

size_t	len_variables(char **variables)
{
	size_t	len;

	len = 0;
	while (variables[len])
		len++;
	return (len);
}

/*
The function check_valid_digit checks if the string is a valid digit.
*/

bool	check_valid_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}
