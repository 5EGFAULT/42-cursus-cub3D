/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:50:14 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/25 18:57:10 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

t_cub	*init_cub(void)
{
	t_cub	*cub;

	cub = (t_cub *)malloc(sizeof(t_cub));
	if (!cub)
		return (NULL);
	cub->map = NULL;
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->f = NULL;
	cub->c = NULL;
	cub->f_color = -1;
	cub->c_color = -1;
	return (cub);
}

/**
 * @brief      Main parsing function Parse 
 * 			the cub file and return a pointer to a t_cub struct
 * @param      file The cub file		
*/
t_cub	*parse_cub(char *file)
{
	t_cub	*cub;

	validate_file_name(file);
	cub = init_cub();
	if (!cub)
		return (NULL);
	parse_conf(file, cub);
	return (cub);
}
