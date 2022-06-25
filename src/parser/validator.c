/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:43:56 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/25 15:03:38 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"
#include "../../inc/parser.h"

/**
 * @brief      check if the file has a valid .cub  and if file 
 * 				exits and have read permition
 * @param      file The cub file		
*/
void	validate_file_name(char *file)
{
	char	*ext;
	char	*error;
	int		fd;

	ext = ".cub";
	error = NULL;
	if (ft_strncmp(ft_strrchr(file, '.'), ext, 5))
		error = "\033[31mError: Invalid file name : \033[33m";
	if (!error)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1 && errno == EACCES)
			error = "\033[31mError: Permission denied : \033[33m";
		else if (fd == -1)
			error = "\033[31mError: File not found : \033[33m";
	}
	if (error)
	{
		write(2, error, ft_strlen(error));
		write(2, file, ft_strlen(file));
		write(2, "\n\033[0m", 6);
		exit(2);
	}
	close(fd);
}
