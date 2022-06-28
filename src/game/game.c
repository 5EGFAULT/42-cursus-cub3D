/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:28:18 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/28 13:18:18 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game.h"

static	void	draw_player(t_game *game)
{
	int		b[2];
	int		e[2];

	b[0] = (game->pos[0] - .5) * game->block[0];
	b[1] = (game->pos[1] - .5) * game->block[1];
	e[0] = (game->pos[0] + .5) * game->block[0];
	e[1] = (game->pos[1] + .5) * game->block[1];
	render_flat(game, 0x4dbc76, b, e);
	game->pos[0] = game->pos[0] * game->block[0];
	game->pos[1] = game->pos[1] * game->block[1];
}

void	run_game(t_cub *cub)
{
	t_game	*game;
	int		e[2];
	double	deg[2];

	game = init_game(cub);
	if (!game)
		exit(3);
	hooks(game);
	render_map2d(game);
	draw_player(game);
	deg[0] = -30;
	while (deg[0] < 30)
	{
		deg[1] = 0.01745329251 * deg[0];
		e[0] = (game->dir[0] * cos(deg[1]) - \
		game->dir[1] * sin(deg[1]) * 200) + game->pos[0];
		e[1] = (game->dir[0] * sin(deg[1]) + \
		game->dir[1] * cos(deg[1]) * 200) + game->pos[1];
		draw_line(game, game->pos, e, 0x764dbc);
		deg[0] += .01;
	}
	mlx_loop(game->mlx);
}
