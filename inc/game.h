/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:28:30 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/26 21:28:46 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "cub3D.h"
# include "utils.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*ea;
	void	*we;
	void	*no;
	void	*so;
	void	*f_texture;
	void	*c_texture;
	int		f;
	int		c;
	char	**map;
	int		map_height;
	int		map_width;
	int		pos[2];
	int		dir[2];
}t_game;

void	run_game(t_cub *cub);


t_game	*init_game(t_cub *cub);
void	load_mlx(t_game *game, t_cub *cub);

#endif