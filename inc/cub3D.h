/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:42:54 by asouinia          #+#    #+#             */
/*   Updated: 2022/07/30 05:38:32 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>

//#ifndef WIN_H
//#define WIN_H 1800
//#endif
//#ifndef WIN_W
//#define WIN_W 3200
//#endif

# ifndef WIN_H
#  define WIN_H 1080
# endif
# ifndef WIN_W
#  define WIN_W 1920
# endif
//# define ROTATE_SPEED 0.2
//# define ROTATE_SPEED 0.02
//# define MOVE_SPEED 20
//# define MOVE_SPEED 2
//# define ROTATE_SPEED 0.02
//# define ROTATE_SPEED M_PI / 4
//# define MOVE_SPEED 5
# define ROTATE_SPEED 0.05
# define MOVE_SPEED 10

typedef struct s_cub
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		f_color;
	int		c_color;
	char	**map;
	int		map_height;
	int		map_width;
	int		pos[2];
	char	dir;
}t_cub;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
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
	double	pos[2];
	int		split;
	double	dir;
	int		block[2];
	int		rotate;
	int		move;
}t_game;

typedef struct s_ray
{
	double	ray[2];
	double	ang;
	double	dist;
	enum {
		S,
		N,
		E,
		W
	}e_side;
}t_ray;

#endif