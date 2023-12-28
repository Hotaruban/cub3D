/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:25:25 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/28 15:26:39 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_data(t_data *data)
{
	if (data->texture.north.addr)
		free(data->texture.north.addr);
	if (data->texture.south.addr)
		free(data->texture.south.addr);
	if (data->texture.west.addr)
		free(data->texture.west.addr);
	if (data->texture.east.addr)
		free(data->texture.east.addr);
	if (data->map)
		free_tab(data->map);
}
