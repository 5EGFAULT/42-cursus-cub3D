/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:28:18 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/30 01:18:18 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game.h"

void	run_game(t_cub *cub)
{
	t_game	*game;

	game = init_game(cub);
	if (!game)
		exit(3);
	hooks(game);
	//render_map2d(game);
	//draw_player(game);
	//draw_rays(game);
	mlx_loop(game->mlx);
}
