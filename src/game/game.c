/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:28:18 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/27 22:54:05 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game.h"

void run_game(t_cub *cub)
{
	t_game *game;
	int B[2];
	int E[2];
	double deg;

	game = init_game(cub);
	if (!game)
		exit(3);
	hooks(game);
	render_map2d(game);
	// draw_line(game, );
	B[0] = (game->pos[0] -.5 )  * game->block[0];
	B[1] = (game->pos[1] -.5 )  * game->block[1];
	E[0] = (game->pos[0] + .5)  * game->block[0];
	E[1] = (game->pos[1] + .5)  * game->block[1];
	render_flat(game, 0x4dbc76, B, E);
	deg = 0.0174532925*135;
	game->dir[0] = game->dir[0] * cos(deg) + game->dir[1] * -sin(deg);
	game->dir[1] =  game->dir[0] * sin(deg) + game->dir[1] * cos(deg);
	draw_line(game->mlx, game->win, B[0] + (game->block[0]/2),B[1] + (game->block[1]/2), \
		((game->dir[0] + game->pos[0])*(game->block[0]/2)), \
		((game->dir[1] + game->pos[1])*(game->block[1]/2)) \
	 , 0x764dbc);
			//((game->dir[0] + game->pos[0])* game->block[0]), 
		//((game->dir[1] + game->pos[1])* game->block[1]) 

	mlx_loop(game->mlx);
}
