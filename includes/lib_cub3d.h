/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_cub3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:48:06 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/28 17:11:57 by jhurpy           ###   ########.fr       */
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
/*                           MACRO DEFINITIONS                                */
/*                                                                            */
/* ************************************************************************** */

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define MEM_ALLOC_FAILED "Memory allocation failed!"
# define NB_ARGS "Wrong number of arguments!"
# define EXTENSION "Wrong file extention!"
# define FILE_NOT_FOUND "File not found or not accessible!"
# define TEXTURE_INVALID "Texture data is not correct!"

# define NORTH data->texture.north
# define SOUTH data->texture.south
# define WEST data->texture.west
# define EAST data->texture.east

/* ************************************************************************** */
/*                                                                            */
/*                        STRUCTURES DEFINITIONS                              */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_draw
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_draw;

typedef struct s_texture
{
	t_draw		north;
	t_draw		south;
	t_draw		west;
	t_draw		east;
	int			floor;
	int			ceiling;
}	t_texture;

typedef struct s_data
{
	t_texture	texture;
	char		**map;
	char		face_dir;
	t_pos		hero;
}	t_data;

/* ************************************************************************** */
/*                                                                            */
/*                        INITIALIZATION FUNCTIONS                            */
/*                                                                            */
/* ************************************************************************** */

void	init_data(t_data *data);
bool	assign_data(t_data *data, char *path_map);
bool	assign_textures(t_data *data, char **tab);
bool	textures_assigned(t_data *data);

/* ************************************************************************** */
/*                                                                            */
/*                        UTILS FUNCTIONS                                     */
/*                                                                            */
/* ************************************************************************** */

void	msg_error(char *msg);
bool	check_extension(char *path, char *ext);
bool	check_access_file(char *path);
void	free_data(t_data *data);
void	free_tab(char **tab);

/* ************************************************************************** */
/*                                                                            */
/*                        TESTER FUNCTIONS                                    */
/*                                                                            */
/* ************************************************************************** */

void	test_parsing(t_data *data, char *str);

#endif
