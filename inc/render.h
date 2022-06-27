/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:50:03 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/27 01:22:59 by asouinia         ###   ########.fr       */
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

#endif