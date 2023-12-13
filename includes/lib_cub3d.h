/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_cub3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:48:06 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/13 18:04:34 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_CUB3D_H
# define LIB_CUB3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

/* ************************************************************************** */
/*                                                                            */
/*                        STRUCTURES DEFINITIONS                              */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_data
{
	t_texture	*texture;
	// data of the map to define the return of the parsing
}			t_data;

typedef struct s_texture
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			floor;
	int			ceiling;
}			t_texture;

/* ************************************************************************** */
/*                                                                            */
/*                        ERROR MANAGEMENT FUNCTIONS                          */
/*                                                                            */
/* ************************************************************************** */



/* ************************************************************************** */
/*                                                                            */
/*                        PARSING FUNCTIONS                                   */
/*                                                                            */
/* ************************************************************************** */




#endif
