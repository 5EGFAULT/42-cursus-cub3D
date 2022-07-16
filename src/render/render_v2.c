/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_v2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:45:29 by asouinia          #+#    #+#             */
/*   Updated: 2022/07/16 22:17:37 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/render.h"

void render_rect(t_game *game, int color, int *begin, int *end)
{
	int i;
	int b[2];
	int e[2];
	char *pixels;
	char *p;
	pixels = mlx_get_data_addr(game->img, &i, &i, &i);
	b[0] = begin[0];
	e[0] = end[0];
	if (begin[0] > end[0])
	{
		b[0] = end[0];
		e[0] = begin[0];
	}
	b[1] = begin[1];
	e[1] = end[1];
	if (begin[1] > end[1])
	{
		b[1] = end[1];
		e[1] = begin[1];
	}
	//printf("%d\t%d\t%d\t%d\n", b[0], b[1], e[0], e[1]);
	while (b[1] < e[1])
	{
		i = b[0];
		p = pixels + ((b[1] * WIN_W + b[0])* 4);
		while (i < e[0])
		{
			//*((unsigned int *)pixels + (i + b[1] * WIN_W)) = color;
			*((unsigned int *)p) = color;
			p += 4;
			i += 1;
		}
		b[1] += 1;
	}
}

void render_mini_map(t_game *game)
{
	int begin[2];
	int end[2];
	int i;
	int j;

	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			begin[0] = j * game->block[0];
			begin[1] = i * game->block[1];
			end[0] = (j + 1) * game->block[0];
			end[1] = (i + 1) * game->block[1];
			if (game->map[i][j] == '0')
				render_rect(game, game->f, begin, end);
			else if (game->map[i][j] == '1')
				render_rect(game, game->c, begin, end);
			else
				render_rect(game, 0xffffff, begin, end);
		}
	}
}
