/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_cub3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:48:06 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/26 14:54:38 by jhurpy           ###   ########.fr       */
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
# define FILE_NOT_FOUND "File not found or does not exist!"
# define TEXTURE_INVALID "Texture data is not correct!"

/* ************************************************************************** */
/*                                                                            */
/*                        STRUCTURES DEFINITIONS                              */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_pos
{
	int			x;
	int			y;
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
/*                        MESSAGE ERROR DEFINITIONS                           */
/*                                                                            */
/* ************************************************************************** */

//void	msg_error_exit(t_data *data, char *msg);
void	msg_error(char *msg);

/* ************************************************************************** */
/*                                                                            */
/*                        PARSING FUNCTIONS                                   */
/*                                                                            */
/* ************************************************************************** */

bool	check_error_file(int ac, char *path_map);
bool	assign_map_data(t_data *data, char *path_map);
bool	assign_textures(int fd, t_data *data);
//bool	init_map(wait for determination for the map structure);

/* ************************************************************************** */
/*                                                                            */
/*                        MEMORY MANAGEMENT FUNCTIONS                         */
/*                                                                            */
/* ************************************************************************** */

bool	alloc_mem_init(t_data *data);
void	free_data(t_data *data);
void	free_2d_array(char **array);

/* ************************************************************************** */
/*                                                                            */
/*                        UTILS FUNCTIONS                                     */
/*                                                                            */
/* ************************************************************************** */

bool	check_valid_variables(char **variables);
bool	check_extension(char *path, char *ext);
bool	check_access_file(char *path);

/* ************************************************************************** */
/*                                                                            */
/*                        TESTER FUNCTIONS                                    */
/*                                                                            */
/* ************************************************************************** */

void	test_parsing(t_data *data, char *str);

#endif
