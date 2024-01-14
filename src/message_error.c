/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:27:45 by jhurpy            #+#    #+#             */
/*   Updated: 2024/01/14 22:20:28 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib_cub3d.h"

/*
The function msg_error displays an error message the program.
*/

void	msg_error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
}

//void	msg_error_exit(t_data *data, char *msg)
//{
//	msg_error(msg);
//	end_program(data);
//	exit(EXIT_FAILURE);
//}
