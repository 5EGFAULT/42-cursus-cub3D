/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:00:31 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/30 00:35:40 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game.h"

int	destroy_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	key_up_hook(int keycode, t_game *game)
{
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		game->move = 0;
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		game->move = 0;
	else if (keycode == KEY_AR_RIGHT || keycode == KEY_AR_LEFT)
		game->rotate = 0;
	return (0);
}

int	key_down_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		destroy_win(game);
	else if (keycode == KEY_AR_LEFT)
		game->rotate = -1;
	else if (keycode == KEY_AR_RIGHT)
		game->rotate = 1;
	else if (keycode == KEY_UP)
		game->move = 1;
	else if (keycode == KEY_DOWN)
		game->move = -1;
	else if (keycode == KEY_LEFT)
		game->move = -2;
	else if (keycode == KEY_RIGHT)
		game->move = 2;
	return (0);
}

void	hooks(t_game *game)
{
	mlx_loop_hook(game->mlx, &render_loop, game);
	mlx_hook(game->win, 2, 1L << 0, key_down_hook, game);
	mlx_hook(game->win, 03, 1L << 1, key_up_hook, game);
	mlx_hook(game->win, 17, 1L << 0, destroy_win, game);
}
