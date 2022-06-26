/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:53:48 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/26 15:17:16 by asouinia         ###   ########.fr       */
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

	ext = ".cub";
	if (ft_strncmp(ft_strrchr(file, '.'), ext, 5))
	{
		write(2, "\033[31mError: Invalid file name : \033[33m", 38);
		write(2, file, ft_strlen(file));
		write(2, "\n\033[0m", 6);
		exit(2);
	}
	validator_file(file);
}

void	validate_cub(t_cub *cub)
{
	validator_obj(cub);
	validator_closed(cub);
	validator_player(cub);
}
