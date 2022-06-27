/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:49:39 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/27 01:26:02 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/render.h"

//void draw_line(void *mlx, void *win, int
//beginX, int beginY, int endX, int endY, int color)
//{
//	double deltaX = endX - beginX; // 10
//	double deltaY = endY - beginY; // 0
//	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
//	deltaX /= pixels; // 1
//	deltaY /= pixels; // 0
//	double pixelX = beginX;
//	double pixelY = beginY;
//	while (pixels)
//	{
//	    mlx_pixel_put(mlx, win, pixelX, pixelY, color);
//	    pixelX += deltaX;
//	    pixelY += deltaY;
//	    --pixels;
//	}
//}

void	render_flat(t_game *game, int color, int *begin, int *end)
{
	int				i;
	int				j[2];
	void			*img;
	char			*pixels;

	img = mlx_new_image(game->mlx, abs(begin[0] - end[0]), \
	abs(begin[1] - end[1]));
	i = 0;
	j[0] = 4;
	j[1] = abs(begin[0] - end[0]) * 4;
	pixels = mlx_get_data_addr(img, j, j + 1, &i);
	j[0] = abs(begin[0] - end[0]) * abs(begin[1] - end[1]);
	while (j[0]--)
	{
			*(unsigned int *)pixels = color;
			pixels+=4;
	}
	mlx_put_image_to_window(game->mlx, game->win, img, begin[0], begin[1]);
}
