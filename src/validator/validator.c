/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:53:48 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/26 00:07:09 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"
#include "../../inc/validator.h"

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

void	validate_cub(t_cub *cub)
{
	//TODO check extern objects
	validator_obj(cub);
	//TODO check map closed
	validator_closed(cub);
	//TODO check map one player position only 
	validator_player(cub);
	//bonus //TODO check hidden door
	
}