/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:28:18 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/27 01:27:58 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game.h"

void	run_game(t_cub *cub)
{
	t_game	*game;
	int		begin[2];
	int		end[2];

	game = init_game(cub);
	if (!game)
		exit(3);
	hooks(game);
	//render_flat(game, game->c);
	begin[0] = 0;
	begin[1] = 0;
	end[0] = WIN_W / 2;
	end[1] = WIN_H / 2;
	render_flat(game, game->c, begin, end);
	begin[0] = WIN_W / 2;
	begin[1] = WIN_H / 2;
	end[0] = WIN_W;
	end[1] = WIN_H;
	render_flat(game, game->f, begin, end);

	begin[0] = WIN_W / 2;
	begin[1] = 0;
	end[0] = WIN_W;
	end[1] = WIN_H / 2;
	render_flat(game, 0xFFFFF, begin, end);
	begin[0] = 0;
	begin[1] = WIN_H / 2;
	end[0] = WIN_W / 2;
	end[1] = WIN_H;
	render_flat(game, 0x12F012, begin, end);
	mlx_loop(game->mlx);
}


