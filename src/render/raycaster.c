/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:16:19 by asouinia          #+#    #+#             */
/*   Updated: 2022/07/23 23:01:30 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/render.h"

void caster(t_game *game)
{
	int rayH[2];
	int rayV[2];
	int pos[2];
	int inc[2];
	//printf("{%d}{%f}\n",game->pos[0],((float)game->pos[0]/(float)game->block[0]));
	//rayH[0] = game->pos[0] + game->block[0];
	//rayH[1] = (rayH[0] - (game->pos[0]/game->block[0])*game->block[0]) * tan(game->dir) + game->pos[1];
	
	//rayV[1] = game->pos[1] + game->block[1];
	//rayV[0] = (rayV[1] - game->pos[1]) * tan(game->dir) + game->pos[0];
	pos[0] = (game->pos[0] / game->block[0]) * game->block[0];
	pos[1] = (game->pos[1] / game->block[1]) * game->block[1];
	//rayH[0] = 0;
	//rayH[1] = 64;
	
	//rayV[0] = 64;
	//rayV[1] = 0;

	//rayV[0] = 64 * cos(-M_PI / 2) + game->pos[0];
	//rayV[1] = 64 * sin(-M_PI / 2) + game->pos[1];

	//rayH[0] = 64 * cos(M_PI / 6) + game->pos[0];
	//rayH[1] = 64 * sin(M_PI / 6) + game->pos[1];

	if (sin(game->dir) > 0)
		inc[1] = pos[1] + game->block[1];
	else
		inc[1] = pos[1];
	if (cos(game->dir) > 0)
		inc[0] = pos[0] + game->block[0];
	else
		inc[0] = pos[0];

	rayV[1] = inc[1];
	rayH[0] = inc[0];

	if (sin(game->dir) > 0)
		rayV[0] = abs(inc[1] - game->pos[1]) / tan(game->dir) + game->pos[0];
	else 
		rayV[0] = -abs(inc[1] - game->pos[1]) / tan(game->dir) + game->pos[0];
	//else
		//rayV[0] = inc[0];
	if (cos(game->dir) > 0)
		rayH[1] = (double)(abs(inc[0] - game->pos[0]) * tan(game->dir)) + game->pos[1];
	else
		rayH[1] = (double)(-abs(inc[0] - game->pos[0]) * tan(game->dir)) + game->pos[1];
	//else
		//rayH[1] = inc[1];
	printf("H:  %d\t%d\n", rayH[0], rayH[1]);
	printf("V:  %d\t%d\n\n", rayV[0], rayV[1]);
	printf("%f\t%f\n\n",sin(game->dir), cos(game->dir));
	printf("%d\t%d\n\n",inc[0], inc[1]);
	inc[0] = game->pos[0] + cos(game->dir) * 1000;
	inc[1] = game->pos[1] + sin(game->dir) * 1000;
	draw_line_v2(game, rayH, game->pos, 0xFF0000);
	draw_line_v2(game, rayV, game->pos, 0x000000);
	draw_line_v2(game, inc, game->pos, 0x00FF00);
}
