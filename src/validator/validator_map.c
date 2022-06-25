/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:00:19 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/25 22:31:06 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"
#include "../../inc/validator.h"

void	validator_obj(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->map_height)
	{
		j = -1;
		while (++j < cub->map_width)
		{
			if (!ft_strchr("NSWE01 ", cub->map[i][j]))
			{
				write(2, "\033[31mError: Extern object found: \033[33m", 39);
				write(2, &cub->map[i][j], 1);
				write(2, "\n\033[0m", 6);
				exit(2);
			}
		}
	}
}

void	validator_player(t_cub *cub)
{
	int	i;
	int	j;
	int	found;

	i = -1;
	found = 0;
	while (++i < cub->map_height)
	{
		j = -1;
		while (++j < cub->map_width)
		{
			if (cub->map[i][j] && ft_strchr("NSWE", cub->map[i][j]))
			{
				found++;
				if (found > 1)
				{
					write(2, "\033[31mError: Double player \
initial position\n\033[0m", 48);
					exit(2);
				}
			}
		}
	}
	if (!found)
	{
		write(2, "\033[31mError: No player initial position found\n\033[0m", 50);
		exit(2);
	}
}