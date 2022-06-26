/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:28:18 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/26 21:18:31 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game.h"

t_game	*init_game(t_cub *cub)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map_height = cub->map_height;
	game->map_width = cub->map_width;
	game->map = cub->map;
	game->pos[0] = cub->pos[0];
	game->pos[1] = cub->pos[1];
	game->map[game->pos[0]][game->pos[1]] = '0';
	game->dir[0] = 0;
	game->dir[1] = 0;
	if (cub->dir == 'N')
		game->dir[1] = -1;
	else if (cub->dir == 'S')
		game->dir[1] = 1;
	else if (cub->dir == 'W')
		game->dir[0] = -1;
	else if (cub->dir == 'E')
		game->dir[0] = 1;
	load_mlx(game, cub);
	return (game);
}

static void	*xpm_file_load(char *file, void *mlx)
{
	void	*img;
	int		i;

	img = mlx_xpm_file_to_image(mlx, file, &i, &i);
	if (img)
		return (img);
	write(2, "\033[31mError: Invalid xpm file : \033[33m", 37);
	write(2, file, ft_strlen(file));
	write(2, "\n\033[0m", 6);
	exit(2);
}

void	load_mlx(t_game *game, t_cub *cub)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit(3);
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "Cub3D");
	if (!game->win)
		exit(3);	game->ea = xpm_file_load(cub->ea, game->mlx);
	game->no = xpm_file_load(cub->no, game->mlx);
	game->we = xpm_file_load(cub->we, game->mlx);
	game->so = xpm_file_load(cub->so, game->mlx);
	if (cub->c_color < 0)
		game->c_texture = xpm_file_load(cub->c, game->mlx);
	else
		game->c = cub->c_color;
	if (cub->f_color < 0)
		game->f_texture = xpm_file_load(cub->f, game->mlx);
	else
		game->f = cub->f_color;
}
