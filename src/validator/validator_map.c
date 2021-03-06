/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:00:19 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/28 12:41:09 by asouinia         ###   ########.fr       */
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

static int	set_init_pos(t_cub *cub, int i, int j)
{
	cub->pos[0] = i;
	cub->pos[1] = j;
	cub->dir = cub->map[i][j];
	return (1);
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
				if (set_init_pos(cub, i, j) && ++found > 1)
				{
					write(2, "\033[31mError: Double player \
initial position\n\033[0m", 48);
					exit(2);
				}
			}
		}
	}
	if (found)
		return ;
	write(2, "\033[31mError: No player initial position found\n\033[0m", 50);
	exit(2);
}

static void	validator_closed_part(t_cub *cub, int i, int j)
{
	int	error;

	error = 0;
	if (cub->map[i][j] == ' ')
	{
		if (j > 0 && ft_strchr("0NWES", cub->map[i][j - 1]))
			error++;
		if (j < cub->map_width - 1 && ft_strchr("0NWES", cub->map[i][j + 1]))
			error++;
		if (i > 0 && ft_strchr("0NWES", cub->map[i - 1][j]))
			error++;
		if (i < cub->map_height - 1 && ft_strchr("0NWES", cub->map[i + 1][j]))
			error++;
		if (error)
		{
			write(2, "\033[31mError: Map not closed\n\033[0m", 32);
			exit(2);
		}
	}
}

void	validator_closed(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->map_height)
	{
		j = -1;
		while (++j < cub->map_width)
		{
			validator_closed_part(cub, i, j);
		}
	}
}
