/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:22:35 by asouinia          #+#    #+#             */
/*   Updated: 2022/07/21 20:11:06 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/render.h"

int	get_distance(int *p1, int *p2)
{
	return (sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2)));
}
void cast_ray(t_game *game, double deg)
{
	int pos[2];
	int dyvec[2];
	int dxvec[2];
	int intersect;

	intersect = 0;
	pos[0] = (game->pos[0] / game->block[0]) * game->block[0];
	pos[1] = (game->pos[1] / game->block[1]) * game->block[1];
	dxvec[0] = game->pos[0];
	dxvec[1] = pos[1];
	dyvec[0] = pos[0];
	dyvec[1] = game->pos[1];
	if (cos(deg) > 0)
		dxvec[0] = pos[0] + game->block[0];
	if (cos(deg) < 0)
		dxvec[0] = pos[0];
	dxvec[1] = (dxvec[0] - game->pos[0]) * tan(deg) + game->pos[1];
	if (sin(deg) > 0)
		dyvec[1] = pos[1] + game->block[1];
	if (sin(deg) < 0)
		dyvec[1] = pos[1];
	dyvec[0] = (dyvec[1] - game->pos[1]) / tan(deg) + game->pos[0];

	while (dxvec[0] / game->block[0] > 0 && dxvec[1] / game->block[1] > 0 && \
	dxvec[0] / game->block[0] < game->map_width && dxvec[1] / game->block[1] < game->map_height && \
	game->map[dxvec[1] / game->block[1]][dxvec[0] / game->block[0]] == '0')
	{
		if (cos(deg) > 0 && game->map[dxvec[1] / game->block[1]][dxvec[0] / game->block[0]] != '0')
			break;
		if (cos(deg) < 0 && game->map[dxvec[1] / game->block[1]][dxvec[0] / game->block[0] - 1] != '0')
			break;
		if (cos(deg) > 0)
			dxvec[0] += game->block[0];
		if (cos(deg) < 0)
			dxvec[0] -= game->block[0];
		dxvec[1] = (dxvec[0] - game->pos[0]) * tan(deg) + game->pos[1];
	}
	while (dyvec[0] / game->block[0] > 0 && dyvec[1] / game->block[1] > 0 && \
	dyvec[0] / game->block[0] < game->map_width && dyvec[1] / game->block[1] < game->map_height && \
	game->map[dyvec[1] / game->block[1]][dyvec[0] / game->block[0]] == '0')
	{
		if (sin(deg) > 0 && game->map[dyvec[1] / game->block[1]][dyvec[0] / game->block[0]] != '0')
			break;
		if (sin(deg) < 0 && game->map[dyvec[1] / game->block[1] - 1][dyvec[0] / game->block[0]] != '0')
			break;
		if (sin(deg) > 0)
			dyvec[1] += game->block[1];
		if (sin(deg) < 0)
			dyvec[1] -= game->block[1];
		dyvec[0] = (dyvec[1] - game->pos[1]) / tan(deg) + game->pos[0];
	}

	// draw_point(game, dxvec, 0xFF00FF);
	// draw_point(game, dyvec, 0x0000FF);
	// draw_line(game, dxvec, game->pos, 0xFF00FF);
	// draw_line(game, dyvec,game->pos, 0x0000FF);
	// draw_point(game, pos, 0xFF0000);
	if (get_distance(game->pos, dxvec) - get_distance(game->pos, dyvec) < 0)
		draw_line_v2(game, dxvec,game->pos, 0x0000FF);
	else
		draw_line_v2(game, dyvec,game->pos, 0x0000FF);
		//draw_line(game, dyvec,game->pos, 0x00FF00);
}

// void	cast_ray(t_game *game, double deg)
//{
// int		pos[2];
// int		dyvec[2];
// int		dxvec[2];

//(void)deg;
// dxvec[0] = game->pos[0];
// dxvec[1] = game->pos[1];
// dyvec[0] = game->pos[0];
// dyvec[1] = game->pos[1];
// pos[0] = (game->pos[0] / game->block[0]) * game->block[0];
// pos[1] = (game->pos[1] / game->block[1]) * game->block[1];
// mlx_pixel_put(game->mlx, game->win, pos[0], pos[1], 0xFF0000);
// mlx_pixel_put(game->mlx, game->win, pos[0], pos[1]-2, 0xFF0000);
// mlx_pixel_put(game->mlx, game->win, pos[0]+2, pos[1]+2 , 0xFF0000);
// mlx_pixel_put(game->mlx, game->win, pos[0]-2, pos[1], 0xFF0000);
// draw_line(game, game->pos, dyvec, 0xFF0000);
//}

void draw_rays(t_game *game)
{
	//int e[2];
	double deg;
	double inc;

	inc = 66 * M_PI / 180;
	inc = inc / WIN_W;
	//printf("%f\n", inc);
	deg = game->dir - 0.523599;
		//cast_ray(game, game->dir);
	while (deg < game->dir + 0.523599)
	{
		cast_ray(game, deg);
		// e[0] = 200 * cos(deg) + game->pos[0];
		// e[1] = 200 * sin(deg) + game->pos[1];
		// draw_line(game, game->pos, e, 0x764dbc);
		 deg += .001;
		// deg += inc;
		//deg += .05;
	}
	//e[0] = 250 * cos(game->dir) + game->pos[0];
	//e[1] = 250 * sin(game->dir) + game->pos[1];
	//draw_line(game, game->pos, e, 0x0000);
	//draw_point(game, game->pos, 0xff0000);
}

void render_grid(t_game *game)
{
	int begin[2];
	int end[2];
	int i;

	i = -1;
	begin[0] = 0;
	end[0] = WIN_W;
	while (++i < game->map_height)
	{
		begin[1] = i * game->block[1];
		end[1] = i * game->block[1];
		draw_line_v2(game, begin, end, 0x000000);
	}
	i = -1;
	begin[1] = 0;
	end[1] = WIN_H;
	while (++i < game->map_width)
	{
		begin[0] = i * game->block[0];
		end[0] = i * game->block[0];
		draw_line_v2(game, begin, end, 0x000000);
	}
}
