/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:25:25 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/30 12:09:47 by jhurpy           ###   ########.fr       */
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

static void	free_img(t_image *img)
{
	if (img->img)
		free(img->img);
	if (img->addr)
		free(img->addr);
}

void	free_data(t_data *data)
{
	free_img(&NORTH);
	free_img(&SOUTH);
	free_img(&WEST);
	free_img(&EAST);
	if (data->map)
		free_tab(data->map);
}
