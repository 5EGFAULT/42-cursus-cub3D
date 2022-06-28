/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:22:35 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/28 16:26:23 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/render.h"

void	draw_player(t_game *game)
{
	int		b[2];
	int		e[2];

	b[0] = game->pos[0] - .5 * game->block[0];
	b[1] = game->pos[1] - .5 * game->block[1];
	e[0] = game->pos[0] + .5 * game->block[0];
	e[1] = game->pos[1] + .5 * game->block[1];
	render_flat(game, 0x4dbc76, b, e);
	game->pos[0] = game->pos[0];
	game->pos[1] = game->pos[1];
}

void	draw_rays(t_game *game)
{
	int		e[2];
	double	deg[2];

	deg[0] = -30;
	while (deg[0] < 30)
	{
		deg[1] = 0.01745329251 * deg[0];
		e[0] = (game->dir[0] * 200 * cos(deg[1]) - game->dir[1] * 200 * \
		sin(deg[1])) + game->pos[0];
		e[1] = (game->dir[0] * 200 * sin(deg[1]) + game->dir[1] * 200 * \
		cos(deg[1])) + game->pos[1];
		draw_line(game, game->pos, e, 0x764dbc);
		deg[0] += 1;
	}
	e[0] = (game->dir[0] * 250) + game->pos[0];
	e[1] = (game->dir[1] * 250) + game->pos[1];
	draw_line(game, game->pos, e, 0x0000);
}
