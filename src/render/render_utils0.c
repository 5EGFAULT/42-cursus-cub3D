/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:49:39 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/28 13:23:12 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/render.h"

void	draw_line(t_game *game, int *begin, int *end, int color)
{
	double	delta[2];
	int		pixels;
	double	pixel[2];

	pixel[0] = begin[0];
	pixel[1] = begin[1];
	delta[0] = end[0] - begin[0];
	delta[1] = end[1] - begin[1];
	pixels = sqrt((delta[0] * delta[0]) + (delta[1] * delta[1]));
	delta[0] /= pixels;
	delta[1] /= pixels;
	while (pixels)
	{
		mlx_pixel_put(game->mlx, game->win, pixel[0], pixel[1], color);
		pixel[0] += delta[0];
		pixel[1] += delta[1];
		--pixels;
	}
}

void	render_flat(t_game *game, int color, int *begin, int *end)
{
	int		i;
	int		j[2];
	void	*img;
	char	*pixels;

	img = mlx_new_image(game->mlx, abs(begin[0] - end[0]), \
	abs(begin[1] - end[1]));
	i = 0;
	j[0] = 4;
	j[1] = abs(begin[0] - end[0]) * 4;
	pixels = mlx_get_data_addr(img, j, j + 1, &i);
	j[0] = abs(begin[0] - end[0]) * abs(begin[1] - end[1]);
	while (j[0]--)
	{
		*(unsigned int *)pixels = color;
		pixels += 4;
	}
	mlx_put_image_to_window(game->mlx, game->win, img, begin[0], begin[1]);
	mlx_destroy_image(game->mlx, img);
}

static void	draw_extra_as_blanc(t_game	*game)
{
	int	begin[2];
	int	end[2];

	begin[0] = game->map_width * game->block[0];
	begin[1] = 0;
	end[0] = WIN_W;
	end[1] = WIN_H;
	render_flat(game, 0x8fd185, begin, end);
	begin[0] = 0;
	begin[1] = game->map_height * game->block[1];
	end[0] = WIN_W;
	end[1] = WIN_H;
	render_flat(game, 0x8fd185, begin, end);
}

void	render_map2d(t_game	*game)
{
	int	begin[2];
	int	end[2];
	int	i;
	int	j;

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
				render_flat(game, game->f, begin, end);
			else if (game->map[i][j] == '1')
				render_flat(game, game->c, begin, end);
			else
				render_flat(game, 0x8fd185, begin, end);
		}
	}
	draw_extra_as_blanc(game);
}
