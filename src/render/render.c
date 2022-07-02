/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:34:26 by asouinia          #+#    #+#             */
/*   Updated: 2022/07/01 22:15:57 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/render.h"

void check_collision_raycast_move(t_game *game, double deg, int *move)
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
	if (dxvec[0] / game->block[0] > 0 && dxvec[1] / game->block[1] > 0 && \
	dxvec[0] / game->block[0] < game->map_width && dxvec[1] / game->block[1] < game->map_height)
	{
		if (cos(deg) > 0 && game->map[dxvec[1] / game->block[1]][dxvec[0] / game->block[0]] != '0')
			{
				intersect = 1;
				//printf("xxxx  cos > 0\n");
				draw_line(game, game->pos, dxvec, 0xff0000);
				draw_point(game, dxvec, 0xff0000);
			}
		else if (cos(deg) < 0 && game->map[dxvec[1] / game->block[1]][dxvec[0] / game->block[0] - 1] != '0')
			{
				intersect = 1;
				//printf("xxxx  cos > 0\n");
				draw_point(game, dxvec, 0xff0000);
				draw_line(game, game->pos, dxvec, 0xff0000);
			}
	}
	if (!intersect && dyvec[0] / game->block[0] > 0 && dyvec[1] / game->block[1] > 0 && \
	dyvec[0] / game->block[0] < game->map_width && dyvec[1] / game->block[1] < game->map_height)
	{
		if (sin(deg) > 0 && game->map[dyvec[1] / game->block[1]][dyvec[0] / game->block[0]] != '0')
			{
				intersect = 1;
				//printf("yyyy  sin > 0\n");
				//draw_line(game, game->pos, dyvec, 0xff0000);
				//draw_point(game, dyvec, 0xff0000);
			}
		else if (sin(deg) < 0 && game->map[dyvec[1] / game->block[1] - 1][dyvec[0] / game->block[0]] != '0')
			{
				intersect = 1;
				//printf("yyyy  sin > 0\n");
				//draw_line(game, game->pos, dyvec, 0xff0000);
				//draw_point(game, dyvec, 0xff0000);
			}
	}
	if (!intersect)
	{
		game->pos[0] = move[0];
		game->pos[1] = move[1];
	}
}

void	move_player(t_game *game)
{
	int	reverse;
	int	move[2];

	reverse = game->move;
	game->dir += game->rotate * ROTATE_SPEED;
	move[0] = game->pos[0];
	move[1] = game->pos[1];
	if (game->move == 1 || game->move == -1)
	{
		if (game->move == 1)
			reverse = 0;
		move[0] += MOVE_SPEED * (cos(game->dir + M_PI * reverse));
		move[1] += MOVE_SPEED * (sin(game->dir + M_PI * reverse));
	}
	else if (game->move == 2 || game->move == -2)
	{
		reverse /= 2;
		move[0] += MOVE_SPEED * (cos(game->dir + M_PI_2 * reverse));
		move[1] += MOVE_SPEED * (sin(game->dir + M_PI_2 * reverse));
	}

	if (move[0] / game->block[0] == game->pos[0] / game->block[0] &&
	move[1] / game->block[1] == game->pos[1] / game->block[1])
	{
		game->pos[0] = move[0];
		game->pos[1] = move[1];
	}
	else
	{
		game->pos[0] = move[0];
		game->pos[1] = move[1];
		//if (game->move == 1 || game->move == -1)
			//check_collision_raycast_move(game, game->dir + M_PI * reverse, move);
		//else if (game->move == 2 || game->move == -2)
			//check_collision_raycast_move(game, game->dir + M_PI_2 * reverse, move);
	}
	//if (move[0] / game->block[0] < game->map_width && move[0] / game->block[0] > -1 &&
	//	move[1] / game->block[1] < game->map_height && move[1] / game->block[1] > -1 &&
	//	game->map[move[1] / game->block[1]][move[0] / game->block[0]] == '0')
	//{
	//	game->pos[0] = move[0];
	//	game->pos[1] = move[1];
	//}
	//if (game->map[move[1]/ game->block[1]][move[0]/ game->block[0]] == '0')
	//{
		//game->pos[0] = move[0];
		//game->pos[1] = move[1];
	//}
}

int	render_loop(t_game *game)
{
	static int	frame;

	if (frame % 60 == 0)
	{
		move_player(game);
		render_map2d(game);
		//render_grid(game);
		draw_player(game);
		draw_rays(game);
	}
	frame++;
	return (0);
}

void	draw_point(t_game	*game, int *pos, int color)
{
	int	begin[2];
	int	end[2];

	begin[0] = pos[0] - 2;
	begin[1] = pos[1] - 2;
	end[0] = pos[0] + 2;
	end[1] = pos[1] + 2;
	render_flat(game, color, begin, end);
}
