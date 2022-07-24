/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:16:19 by asouinia          #+#    #+#             */
/*   Updated: 2022/07/24 18:13:55 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/render.h"


double	*cast_y(t_game *game, double ang)
{
	double	*ray;
	int		pos[2];
	int		inc[2];

	ray = (double *)malloc(sizeof(double) * 2);
	if (!ray)
		exit(EXIT_FAILURE);
	pos[0] = floor(game->pos[0] / game->block[0]) * game->block[0];
	pos[1] = floor(game->pos[1] / game->block[1]) * game->block[1];
	if (sin(ang) > 0)
		inc[1] = pos[1] + game->block[1];
	else
		inc[1] = pos[1];
	if (cos(ang) > 0)
		inc[0] = pos[0] + game->block[0];
	else
		inc[0] = pos[0];
	ray[1] = inc[1];
	if (sin(ang) > 0)
		ray[0] = fabs(inc[1] - game->pos[1]) / tan(ang) + game->pos[0];
	else
		ray[0] = -fabs(inc[1] - game->pos[1]) / tan(ang) + game->pos[0];
	pos[0] = (int)game->pos[0];
	pos[1] = (int)game->pos[1];
	inc[0] = (int)ray[0];
	inc[1] = (int)ray[1];
	draw_line_v2(game, inc, pos, 0xFF0000);
	return (ray);
}
double	*cast_x(t_game *game, double ang)
{
	double	*ray;
	int		pos[2];
	int		inc[2];

	ray = (double *)malloc(sizeof(double) * 2);
	if (!ray)
		exit(EXIT_FAILURE);
	pos[0] = floor(game->pos[0] / game->block[0]) * game->block[0];
	pos[1] = floor(game->pos[1] / game->block[1]) * game->block[1];
	if (sin(ang) > 0)
		inc[1] = pos[1] + game->block[1];
	else
		inc[1] = pos[1];
	if (cos(ang) > 0)
		inc[0] = pos[0] + game->block[0];
	else
		inc[0] = pos[0];
	if (cos(game->dir) > 0)
		ray[1] = (fabs(inc[0] - game->pos[0]) * tan(game->dir)) + game->pos[1];
	else
		ray[1] = (-fabs(inc[0] - game->pos[0]) * tan(game->dir)) + game->pos[1];
	ray[0] = inc[0];
	pos[0] = (int)game->pos[0];
	pos[1] = (int)game->pos[1];
	inc[0] = (int)ray[0];
	inc[1] = (int)ray[1];
	draw_line_v2(game, inc, pos, 0x0000FF);
	return (ray);
}


void caster(t_game *game)
{
	//int rayH[2];
	//int rayV[2];
	int pos[2];
	int inc[2];
	// printf("{%d}{%f}\n",game->pos[0],((float)game->pos[0]/(float)game->block[0]));
	// rayH[0] = game->pos[0] + game->block[0];
	// rayH[1] = (rayH[0] - (game->pos[0]/game->block[0])*game->block[0]) * tan(game->dir) + game->pos[1];

	// rayV[1] = game->pos[1] + game->block[1];
	// rayV[0] = (rayV[1] - game->pos[1]) * tan(game->dir) + game->pos[0];
	//pos[0] = floor(game->pos[0] / game->block[0]) * game->block[0];
	//pos[1] = floor(game->pos[1] / game->block[1]) * game->block[1];

	//if (sin(game->dir) > 0)
	//	inc[1] = pos[1] + game->block[1];
	//else
	//	inc[1] = pos[1];
	//if (cos(game->dir) > 0)
	//	inc[0] = pos[0] + game->block[0];
	//else
	//	inc[0] = pos[0];

	//rayV[1] = inc[1];
	//rayH[0] = inc[0];

	//if (sin(game->dir) > 0)
	//	rayV[0] = fabs(inc[1] - game->pos[1]) / tan(game->dir) + game->pos[0];
	//else if (sin(game->dir) < 0)
	//	rayV[0] = -fabs(inc[1] - game->pos[1]) / tan(game->dir) + game->pos[0];
	//else
	//	rayV[0] = WIN_W;
	//if (cos(game->dir) > 0)
	//	rayH[1] = (double)(fabs(inc[0] - game->pos[0]) * tan(game->dir)) + game->pos[1];
	//else if (cos(game->dir) < 0)
	//	rayH[1] = (double)(-fabs(inc[0] - game->pos[0]) * tan(game->dir)) + game->pos[1];
	//else
	//	rayH[1] = WIN_H;
	//// printf("H:  %d\t%d\n", rayH[0], rayH[1]);
	//// printf("V:  %d\t%d\n\n", rayV[0], rayV[1]);
	//// printf("%f\t%f\n\n",sin(game->dir), cos(game->dir));
	//// printf("%d\t%d\n\n",inc[0], inc[1]);
	////if(cos(game->dir) == 0)
	//	//printf("cos(%f) == %f\n", game->dir, cos(game->dir));
	////else if(sin(game->dir) == 0)
	//	//printf("sin(%f) == %f\n\n", game->dir, sin(game->dir));
	////printf("%f\t%f\n\n",cos(game->dir) * 64, sin(game->dir) * 64);
	////else
	//	//printf("none cos(%Lf) == %f\tsin(%Lf) == %.f\n", game->dir, cos(game->dir)*64, game->dir, sin(game->dir)*64);
	inc[0] = game->pos[0] + cos(game->dir) * 128;
	inc[1] = game->pos[1] + sin(game->dir) * 128;
	pos[0] = (int)game->pos[0];
	pos[1] = (int)game->pos[1];
	//draw_line_v2(game, rayH, pos, 0xFF0000);
	//draw_line_v2(game, rayV, pos, 0x000000);
	//draw_line_v2(game, inc, pos, 0x00FF00);
	// printf("%.8f\n\n",game->dir);
	double *rayH = cast_y(game, game->dir);
	(void)rayH;
	double *rayV = cast_x(game, game->dir);
	(void)rayV;
}
