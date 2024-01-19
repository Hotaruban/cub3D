/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_cub3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:48:06 by jhurpy            #+#    #+#             */
/*   Updated: 2024/01/19 18:40:53 by jhurpy           ###   ########.fr       */
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

# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1

# define NORTH	data->texture.north
# define SOUTH	data->texture.south
# define WEST	data->texture.west
# define EAST	data->texture.east
# define HERO	data->hero

# define MEM_ALLOC_FAILED	"Memory allocation failed!"
# define FILE_FAILED		"Failed to open the file!"
# define NB_ARGS			"Wrong number of arguments!"
# define EXTENSION			"Wrong file extention!"
# define FILE_NOT_FOUND		"File not found or not accessible!"
# define TEXTURE_INVALID	"Texture data is not correct!"
# define COLOR_INVALID		"Color data is not correct!"
# define MAP_INVALID		"Map data is not correct!"
# define MAP_NOT_FOUND		"Map data not found!"
# define HERO_INVALID		"Hero position is not correct!"
# define HERO_NOT_FOUND		"Hero position not found!"
# define FAIL_WINDOW		"Fail to construct window."
# define FAIL_MINIMAP		"Fail to construct minimap image."
# define FAIL_RAYCASTING	"Fail to construct ray-casting image."

/* for window size */
# define HEIGHT 768
# define WIDTH 1024

/* angles (half fov actually) */
# define PI 3.14159265359
# define FOV 0.4235987756

/* move */
# define SPEED 0.05

/* ************************************************************************** */
/*                                                                            */
/*                        STRUCTURES DEFINITIONS                              */
/*                                                                            */
/* ************************************************************************** */

typedef enum e_dir
{
	N,
	E,
	S,
	W
}	t_dir;

typedef struct s_draw
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		tex_h;
	int		tex_w;
}	t_draw;

typedef struct s_cor_int
{
	int	x;
	int	y;
}	t_cor_int;

typedef struct s_cor_db
{
	double	x;
	double	y;
}	t_cor_db;

typedef struct s_rays
{
	double		step_ang;
	t_cor_db	dir;
	t_cor_db	side_dist;
	t_cor_int	step;
	t_cor_db	delta;
	t_cor_int	map;
	bool		side_hit;
	double		perp_dist;
	int			wall_h;
	int			wall_hit_x;
	t_draw		wall;
}	t_rays;

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	r;
	bool	l;
}	t_keys;

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
	void		*mlx;
	void		*win;
	t_draw		mini_map;
	t_texture	texture;
	char		**map;
	int			map_height;
	t_draw		rc;
	double		face_ang;
	t_cor_db	hero;
	t_keys		key;
}	t_data;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

/* ************************************************************************** */
/*                                                                            */
/*                        INITIALIZATION FUNCTIONS                            */
/*                                                                            */
/* ************************************************************************** */

void	init_data(t_data *data);
void	assign_data(t_data *data, char *path_map);
void	assign_textures(t_data *data, char **tab);
bool	assign_map(int fd, t_list **list);
void	check_valid_textures(t_data *data);
bool	open_file_img(t_data *data);
void	check_valid_map(t_data *data);

/* ************************************************************************** */
/*                                                                            */
/*                        UTILS FUNCTIONS                                     */
/*                                                                            */
/* ************************************************************************** */

size_t	len_variables(char **variables);
bool	check_extension(char *path, char *ext);
bool	check_access_file(char *path);
bool	check_valid_digit(char *str);
bool	find_hero_line(t_data *data, int y);
void	check_hero_pos(t_data *data);
void	check_in_square(char **map, int x, int y);
void	pass_list_to_tab(t_data *data, t_list *list);
void	assign_variable(char **var, char *str);
void	free_data(t_data *data);
void	free_tab(char **tab);
void	msg_error(char *msg);

/* ************************************************************************** */
/*                                                                            */
/*                      RAYCASTING FUNCTIONS                                  */
/*                                                                            */
/* ************************************************************************** */

/* rc_utils.c */
int		end_program(t_data *rc);
int		key_press(int key, t_data *data);
int		key_release(int key, t_data *data);
void	img_draw_pixel(t_draw *data, int x, int y, unsigned int color);
void	put_imgs(t_data *data);

/* rc_init.c */
void	data_init(t_data *data);
void	init_draw(void *mlx, t_draw *tar, int width, int height);

/* rc_move.c */
void	move_hero(t_data *data);

/* rc_draw.c */
void	img_draw_unit(
			t_draw *target, int unit_size, t_cor_int pos, unsigned int color);
void	img_draw_line(
			t_draw *target, t_cor_int cur, t_cor_int end, unsigned int color);
void	img_draw_background(t_data *data);
void	img_draw_wall(
			t_draw *target, t_cor_int pos, t_cor_int end, t_draw wall);

/* rc_loop.c */
int		data_loop(t_data *data);

/* rc_raycast.c */
void	draw_rc(t_data *data);

/* rc_raycast2.c */
void	get_crutial_val(t_data *data, t_rays *rays);

#endif
