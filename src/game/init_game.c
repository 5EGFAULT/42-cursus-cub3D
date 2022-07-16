/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:28:18 by asouinia          #+#    #+#             */
/*   Updated: 2022/07/16 20:34:47 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game.h"
#include <mlx.h>

static void	game_map_fill(t_cub *cub, t_game *game)
{
	int		i;
	char	*line;

	game->map = malloc(sizeof(char *) * cub->map_height - 2);
	if (!game->map)
		exit(3);
	i = 0;
	while (++i < cub->map_height - 1)
	{
		line = ft_substr(cub->map[i] + 1, cub->map[i] + \
		ft_strlen(cub->map[i]) - 1);
		free(cub->map[i]);
		game->map[i - 1] = line;
	}
	free(cub->map[0]);
	free(cub->map);
	game->map_height = cub->map_height - 2;
	game->map_width = cub->map_width - 2;
	game->dir = 0;
	game->map[cub->pos[0] - 1][cub->pos[1] - 1] = '0';
}

t_game	*init_game(t_cub *cub)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game_map_fill(cub, game);
	game->block[1] = floor(WIN_H / (game->map_height));
	game->block[0] = floor(WIN_W / (game->map_width));
	game->block[0] = 64;
	game->block[1] = 64;
	game->pos[1] = (cub->pos[0] - 1) * game->block[1];
	game->pos[0] = (cub->pos[1] - 1) * game->block[0];
	if (cub->dir == 'N')
		game->dir = 3 * M_PI_2;
	else if (cub->dir == 'S')
		game->dir = M_PI_2;
	else if (cub->dir == 'W')
		game->dir = M_PI;
	else if (cub->dir == 'E')
		game->dir = 0;
	game->rotate = 0;
	game->move = 0;
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
		exit(3);
	game->ea = xpm_file_load(cub->ea, game->mlx);
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
