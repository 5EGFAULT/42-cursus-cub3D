/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:50:03 by asouinia          #+#    #+#             */
/*   Updated: 2022/07/16 13:03:11 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "cub3D.h"
# include "utils.h"

void	render_flat(t_game *game, int color, int *begin, int *end);
void	render_map2d(t_game *game);
void	draw_line(t_game *game, int *begin, int *end, int color);
void	draw_player(t_game *game);
void	draw_rays(t_game *game);
int		render_loop(t_game *game);
void	move_player(t_game *game);
void	render_grid(t_game	*game);
void	draw_point(t_game	*game, int *pos, int color);
int		get_distance(int *p1, int *p2);

#endif