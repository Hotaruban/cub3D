/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:25:25 by jhurpy            #+#    #+#             */
/*   Updated: 2024/01/19 16:52:59 by ychen2           ###   ########.fr       */
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

static void	free_img(t_draw *img)
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
