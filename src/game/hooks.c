/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:00:31 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/28 16:25:49 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game.h"

int	destroy_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		destroy_win(game);
	if (keycode == KEY_AR_LEFT || keycode == KEY_AR_RIGHT)
		rotate_player(game, keycode);
	else
		move_player(game, keycode);
	return (0);
}

void	move_player(t_game *game, int keycode)
{
	int	pas;

	pas = 2;
	if (keycode == KEY_UP)
		game->pos[1] += -pas;
	else if (keycode == KEY_DOWN)
		game->pos[1] += pas;
	else if (keycode == KEY_LEFT)
		game->pos[0] += -pas;
	else if (keycode == KEY_RIGHT)
		game->pos[0] += pas;
	render_map2d(game);
	draw_player(game);
	draw_rays(game);
}

void	rotate_player(t_game *game, int keycode)
{
	double	pas;
	double	newdir[2];

	if (keycode == KEY_AR_LEFT)
		pas = 0.01745329251 * -5;
	else
		pas = 0.01745329251 * 5;
	newdir[0] = game->dir[0] * cos(pas) - game->dir[1] * sin(pas);
	newdir[1] = game->dir[0] * sin(pas) + game->dir[1] * cos(pas);
	game->dir[0] = newdir[0];
	game->dir[1] = newdir[1];
	render_map2d(game);
	draw_player(game);
	draw_rays(game);
}

void	hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->win, 17, 1L << 0, destroy_win, game);
}
