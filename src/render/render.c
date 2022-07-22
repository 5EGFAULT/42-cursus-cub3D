/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:34:26 by asouinia          #+#    #+#             */
/*   Updated: 2022/07/22 14:47:09 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/render.h"

void	collision(t_game *game, int *move)
{
	if (game->pos[0] < move[0] && game->map[game->pos[1] / game->block[1]][move[0] / game->block[0]] != '0')
		move[0] = (move[0] / game->block[0]) * game->block[0] - 1;
	else if (game->map[game->pos[1] / game->block[1]][move[0] / game->block[0]] != '0')
		move[0] = (move[0] / game->block[0] + 1) * game->block[0] + 1;
	if (game->pos[1] < move[1] && game->map[move[1] / game->block[1]][game->pos[0] / game->block[0]] != '0')
		move[1] = (move[1] / game->block[1]) * game->block[1] - 1;
	else if (game->map[move[1] / game->block[1]][game->pos[0] / game->block[0]] != '0')
		move[1] = (move[1] / game->block[1] + 1) * game->block[1] + 1;
	game->pos[0] = move[0];
	game->pos[1] = move[1];
	//if (game->pos[0] < 0)
	//	game->pos[0] = 0;
	//else if (game->pos[0] > WIN_W)
	//	game->pos[0] = WIN_W;
	//if (game->pos[1] < 0)
	//	game->pos[1] = 0;
	//else if (game->pos[1] > WIN_H)
	//	game->pos[1] = WIN_H;
}

void	move_player(t_game *game)
{
	int reverse;
	int move[2];

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
		// game->pos[0] = move[0];
		// game->pos[1] = move[1];
		collision(game, move);
		// if (game->move == 1 || game->move == -1)
		//	check_collision_raycast_move(game, game->dir + M_PI * reverse, move);
		// else if (game->move == 2 || game->move == -2)
		//	check_collision_raycast_move(game, game->dir + M_PI_2 * reverse, move);
	}
	// if (move[0] / game->block[0] < game->map_width && move[0] / game->block[0] > -1 &&
	//	move[1] / game->block[1] < game->map_height && move[1] / game->block[1] > -1 &&
	//	game->map[move[1] / game->block[1]][move[0] / game->block[0]] == '0')
	//{
	//	game->pos[0] = move[0];
	//	game->pos[1] = move[1];
	// }
	// if (game->map[move[1]/ game->block[1]][move[0]/ game->block[0]] == '0')
	//{
	// game->pos[0] = move[0];
	// game->pos[1] = move[1];
	//}
}

void	draw_top_down(t_game *game)
{
	char *p;
	int x;
	int y;

	y = 0;
	p = mlx_get_data_addr(game->img, &x, &x, &x);
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			if (y > game->split)
				*(unsigned int *)(p + x * 4 + y * WIN_W * 4) = 0x232323;
			else
				*(unsigned int *)(p + x * 4 + y * WIN_W * 4) = 0xd4d4d4;
			x++;
		}
		y++;
	}
}

int render_loop(t_game *game)
{
	static int frame;

	if (frame % 60 == 0)
	{
		// render_map2d(game);
		// render_grid(game);
		// draw_player(game);
		move_player(game);
		draw_top_down(game);
		draw_rays(game);
		//render_mini_map(game);
		//render_grid(game);
		//draw_player(game);
		mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	}
	frame++;
	return (0);
}

void draw_point(t_game *game, int *pos, int color)
{
	int begin[2];
	int end[2];

	begin[0] = pos[0] - 2;
	begin[1] = pos[1] - 2;
	end[0] = pos[0] + 2;
	end[1] = pos[1] + 2;
	render_flat(game, color, begin, end);
}
