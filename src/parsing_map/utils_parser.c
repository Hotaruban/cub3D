/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:56:15 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/13 23:17:06 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_cub3d.h"

/*
The function parce_space parse the line untill it is space and
increment the index.
*/

void	parse_space(char *line, int *index)
{
	while (line[*index] == 32)
		(*index)++;
}

/*
The function parse_string parse the line untill it is ft_isalnum or ft_isprint
is true and increment the index.
Return the string parsed or NULL if the string is empty or if the next
character is not space or a newline.
*/

char	*parse_string(char *line, int *index)
{
	int		start_index;

	start_index = *index;
	while (ft_isalnum(line[*index]) || ft_isprint(line[*index]))
		(*index)++;
	if (start_index == *index || (line[*index] != 32 && line[*index] != '\n'))
		return (NULL);
	return (ft_substr(line, start_index, *index - start_index));
}
