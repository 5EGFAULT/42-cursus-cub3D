/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:34:26 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/30 01:18:41 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/render.h"

void	move_player(t_game *game)
{
	int	reverse;

	reverse = game->move;
	game->dir += game->rotate * ROTATE_SPEED;
	if (game->move == 1 || game->move == -1)
	{
		game->pos[0] += reverse * MOVE_SPEED * (cos(game->dir));
		game->pos[1] += reverse * MOVE_SPEED * (sin(game->dir));
	}
	else if (game->move == 2 || game->move == -2)
	{
		reverse /= 2;
		game->pos[0] += MOVE_SPEED * (cos(game->dir + M_PI_2 * reverse));
		game->pos[1] += MOVE_SPEED * (sin(game->dir + M_PI_2 * reverse));
	}
}

int	render_loop(t_game *game)
{
	static int	frame;

	if (frame % 500 == 0)
	{
		move_player(game);
		render_map2d(game);
		render_grid(game);
		draw_player(game);
		draw_rays(game);
	}
	frame++;
	return (0);
}
