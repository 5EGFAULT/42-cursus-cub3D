/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:22:35 by asouinia          #+#    #+#             */
/*   Updated: 2022/07/22 22:14:20 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/render.h"

int get_distance(int *p1, int *p2)
{
	return (sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2)));
}
void cast_ray(t_game *game, double deg, int idx)
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

	while (dxvec[0] / game->block[0] > 0 && dxvec[1] / game->block[1] > 0 &&
		   dxvec[0] / game->block[0] < game->map_width && dxvec[1] / game->block[1] < game->map_height &&
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
	while (dyvec[0] / game->block[0] > 0 && dyvec[1] / game->block[1] > 0 &&
		   dyvec[0] / game->block[0] < game->map_width && dyvec[1] / game->block[1] < game->map_height &&
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
	int ccc = 0x12f212;
	if (get_distance(game->pos, dxvec) - get_distance(game->pos, dyvec) < 0)
	{
		dyvec[0] = dxvec[0];
		dyvec[1] = dxvec[1];
	}
	//draw_line_v2(game, dyvec, game->pos, ccc);
	//dyvec[0] = dyvec[0] / game->block[0];
	//dyvec[1] = dyvec[1] / game->block[1];
	//dxvec[0] = game->pos[0] / game->block[0];
	//dxvec[1] = game->pos[1] / game->block[1];
	// draw_line(game, dyvec,game->pos, 0x00FF00);
	double lh = get_distance(game->pos, dyvec) * cos(game->dir - deg);
		lh =  (game->block[1] / lh) * ((WIN_W /2) * tan(M_PI / 3));
	dxvec[1] = game->split - lh / 2;
	dxvec[0] = idx;
	pos[1] = game->split + lh / 2;
	pos[0] = idx;
	// draw_line_v2(game, dyvec, game->pos, 0x00ffff);

	// deg = deg - deg * ((int)deg / 2 * M_PI);

	// printf("%f\n", deg);
	//if (cos(deg) > 0)
	//{
	//	if (sin(deg) > 0)
	//		ccc = 0xF1C40F; // east
	//	else
	//		ccc = 0x28B463; // west
	//}
	//else
	//{
	//	if (sin(deg) > 0)
	//		ccc = 0xFF5733; // north
	//	else
	//		ccc = 0x3498DB; // south
	//}
	double val = sin(M_PI / 4);
	if(sin(deg) > val)
		ccc = 0xF1C40F; // north
	else if(sin(deg) < -val)
		ccc = 0x28B463; // south
	else if(cos(deg) > val)
		ccc = 0xFF5733; // east
	else
		ccc = 0x3498DB; // west

	draw_line_v2(game, dxvec, pos, ccc);
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
	// int e[2];
	double deg;
	double inc;
	int idx;

	// inc = 66 * M_PI / 180;
	inc = M_PI / 3;
	inc = inc / WIN_W;
	// printf("%f\n", inc);
	deg = game->dir - M_PI / 6;
	idx = 0;
	while (deg <= game->dir + M_PI / 6)
	{
		cast_ray(game, deg, idx);
		deg += inc;
		idx++;
	}
	// e[0] = 250 * cos(game->dir) + game->pos[0];
	// e[1] = 250 * sin(game->dir) + game->pos[1];
	// draw_line(game, game->pos, e, 0x0000);
	// draw_point(game, game->pos, 0xff0000);
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
