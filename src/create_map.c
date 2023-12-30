/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:01:14 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/30 13:04:48 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

/*
The function find_hero_line find the line where the hero is and assign
the hero position to the data structure.
*/

bool	find_hero_line(t_data *data, int y)
{
	bool	hero_found;
	int		x;

	hero_found = false;
	x = 0;
	while (data->map[y][x] != '\0')
	{
		if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
			|| data->map[y][x] == 'W' || data->map[y][x] == 'E')
		{
			HERO.x = (double)x;
			HERO.y = (double)y;
			data->face_dir = data->map[y][x];
			data->map[y][x] = '0';
			hero_found = true;
		}
		x++;
	}
	return (hero_found);
}

/*
The function line_empty checks if the line is empty and return true if it is.
*/

static bool	line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

/*
The function assign_map copy every line of the map file in a linked list.
*/

bool	assign_map(int fd, t_list **list)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL && line_empty(line) == true)
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line != NULL && line_empty(line) == false)
	{
		if (line != NULL)
			ft_lstadd_back(list, ft_lstnew(line));
		line = get_next_line(fd);
	}
	while (line != NULL && line_empty(line) == true)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line != NULL)
		return (false);
	return (true);
}

/*
The function pass_list_to_tab copy the linked list in a tab.
*/

void	pass_list_to_tab(t_data *data, t_list *list)
{
	int		i;
	t_list	*tmp;

	data->map = (char **)malloc(sizeof(char *) * (ft_lstsize(list) + 1));
	i = 0;
	while (list != NULL)
	{
		assign_variable(&data->map[i], list->content);
		tmp = list;
		list = list->next;
		free(tmp->content);
		free(tmp);
		i++;
	}
	data->map[i] = NULL;
}
