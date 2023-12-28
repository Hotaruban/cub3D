/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:56:15 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/28 15:41:14 by jhurpy           ###   ########.fr       */
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
