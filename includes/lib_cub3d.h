/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_cub3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:48:06 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/21 14:52:13 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_CUB3D_H
# define LIB_CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"

/* ************************************************************************** */
/*                                                                            */
/*                        STRUCTURES DEFINITIONS                              */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_texture
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			floor_color;
	int			ceiling_color;
}	t_texture;

typedef struct s_data
{
	t_texture	*texture;
}	t_data;

/* ************************************************************************** */
/*                                                                            */
/*                        ERROR MANAGEMENT FUNCTIONS                          */
/*                                                                            */
/* ************************************************************************** */

void	msg_error_parsing(char *msg);
bool	check_error_file(int ac, char *path_map);

/* ************************************************************************** */
/*                                                                            */
/*                        PARSING FUNCTIONS                                   */
/*                                                                            */
/* ************************************************************************** */

void	init_data(t_data *data, char *path_map);
bool	init_textures(int fd, t_texture *texture);
//bool	init_map(wait for determination for the map structure);
//void	parse_space(char *line, int *index);
//char	*parse_string(char *line, int *index);

/* ************************************************************************** */
/*                                                                            */
/*                        MEMORY MANAGEMENT FUNCTIONS                         */
/*                                                                            */
/* ************************************************************************** */

t_data	*allocate_memory(t_data *data);

/* ************************************************************************** */
/*                                                                            */
/*                        UTILS FUNCTIONS                                     */
/*                                                                            */
/* ************************************************************************** */

void	free_2d_array(char **array);
void	free_texture(t_texture *texture);
void	free_data(t_data *data);

#endif
