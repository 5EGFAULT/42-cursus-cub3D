/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:43:56 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/25 14:12:15 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"
#include "../../inc/utils.h"
#include "../../inc/parser.h"

void	validate_file_name(char *file)
{
	char	*ext;
	char	*error;

	ext = ".cub";
	error = NULL;
	if (ft_strncmp(ft_strrchr(file, '.'), ext, 5))
		error = "\033[31mError: Invalid file name : \033[33m";
	if (!error)
	{
		
	}
	if (error)
	{
		write(2, error, ft_strlen(error));
		write(2, file, ft_strlen(file));
		write(2, "\n\033[0m", 6);
		exit(2);
	}
}