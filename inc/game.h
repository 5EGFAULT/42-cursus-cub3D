/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:28:30 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/28 14:42:58 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "render.h"
# ifndef KEY_MAP
#  define KEY_MAP
#  define KEY_ESC		53
#  define KEY_UP		13
#  define KEY_DOWN		1
#  define KEY_LEFT		0
#  define KEY_RIGHT		2
#  define KEY_AR_RIGHT	124
#  define KEY_AR_LEFT	123
# endif

void	run_game(t_cub *cub);

t_game	*init_game(t_cub *cub);
void	load_mlx(t_game *game, t_cub *cub);

void	hooks(t_game *game);
void	move_player(t_game *game, int keycode);
void	rotate_player(t_game *game, int keycode);

#endif