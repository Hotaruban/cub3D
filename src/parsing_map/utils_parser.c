/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:56:15 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/21 17:52:54 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib_cub3d.h"

/*
The function counts the number of strings in the line.
*/

static size_t	len_variables(char **variables)
{
	size_t	len;

	len = 0;
	while (variables[len])
		len++;
	return (len);
}

/*
The function checks if the variables are printable characters.
*/

bool	check_valide_variables(char **variables)
{
	int	index_var;
	int	index_char;

	index_var = 0;
	if (len_variables(variables) > 2)
	{
		printf("HERE check_valide_variables\n");
		return (false);
	}
	while (variables[index_var])
	{
		index_char = 0;
		while (variables[index_var][index_char])
		{
			if (variables[index_var][index_char] == '\n'
				&& variables[index_var][index_char + 1] == '\0')
				break ;
			if (!ft_isprint(variables[index_var][index_char]))
			{
				printf("--%c--\n", variables[index_var][index_char]);
				printf("HERE check_valide_variables if condition\n");
				return (false);
			}
			index_char++;
		}
		index_var++;
	}
	return (true);
}
