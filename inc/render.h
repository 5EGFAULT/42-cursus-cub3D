/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:50:03 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/28 13:00:48 by asouinia         ###   ########.fr       */
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
#endif