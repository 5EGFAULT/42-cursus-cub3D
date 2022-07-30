/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:16:19 by asouinia          #+#    #+#             */
/*   Updated: 2022/07/30 06:17:58 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/render.h"

void init_increments(double *inch, double *incv, t_ray *ray, t_game *game)
{
	if (sin(ray->ang) > 0)
	{
		inch[1] = game->block[0];
		inch[0] = game->block[1] / tan(ray->ang);
	}
	else
	{
		inch[1] = -game->block[0];
		inch[0] = -game->block[1] / tan(ray->ang);
	}
	if (cos(ray->ang) > 0)
	{
		incv[0] = game->block[1];
		incv[1] = game->block[0] * tan(ray->ang);
	}
	else
	{
		incv[0] = -game->block[1];
		incv[1] = -game->block[0] * tan(ray->ang);
	}
}

double fget_dist(double *p1, double *p2)
{
	return (sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2)));
}

short is_wall(t_game *game, double *rayh, double *rayv, int inc_v)
{
	if (inc_v <= 1)
	{
		if (rayv[1] >= game->map_height * game->block[1] ||
			rayv[0] >= game->map_width * game->block[0] ||
			rayv[1] < 0 || rayv[0] < 0)
			return (0);
		if (game->map[(int)(rayv[1] /
							game->block[1])][(int)(rayv[0] / game->block[0]) - inc_v] != '0')
			return (0);
		return (1);
	}
	if (rayh[1] >= game->map_height * game->block[1] ||
		rayh[0] >= game->map_width * game->block[0] ||
		rayh[1] < 0 || rayh[0] < 0)
		return (0);
	if (game->map[(int)(rayh[1] /
						game->block[1]) -
				  (inc_v >> 4)][(int)(rayh[0] / game->block[0])] != '0')
		return (0);
	return (1);
}

void set_ray(short inc_v, t_ray *ray, double *rayh, double *rayv)
{
	if (inc_v <= 1)
	{
		ft_memcpy(ray->ray, rayv, sizeof(double) * 2);
		ray->e_side = W;
		if (cos(ray->ang) > 0)
			ray->e_side = E;
	}
	else
	{
		ft_memcpy(ray->ray, rayh, sizeof(double) * 2);
		ray->e_side = N;
		if (sin(ray->ang) > 0)
			ray->e_side = S;
	}
}

int set_incv(double ang, double *pos, double *rayh, double *rayv)
{
	int inc_v;

	inc_v = 0;
	if (fget_dist(pos, rayv) > fget_dist(pos, rayh))
	{
		if (sin(ang) < 0)
			inc_v = 1 << 4;
		else
			inc_v = 1 << 3;
	}
	else
	{
		if (cos(ang) < 0)
			inc_v = 1;
		else
			inc_v = 0;
	}
	return (inc_v);
}

void extend_ray(t_game *game, t_ray *ray, double *rayh, double *rayv)
{
	double inch[2];
	double incv[2];
	int inc_v;

	inc_v = set_incv(ray->ang, game->pos, rayh, rayv);
	init_increments(inch, incv, ray, game);
	while (is_wall(game, rayh, rayv, inc_v))
	{
		if (inc_v <= 1)
		{
			rayv[1] += incv[1];
			rayv[0] += incv[0];
		}
		else
		{
			rayh[1] += inch[1];
			rayh[0] += inch[0];
		}
		inc_v = set_incv(ray->ang, game->pos, rayh, rayv);
	}
	set_ray(inc_v, ray, rayh, rayv);
}

void cast_one(t_game *game, int *pos, t_ray *ray)
{
	double rayh[2];
	double rayv[2];
	int inc[2];

	if (sin(ray->ang) > 0)
		inc[1] = pos[1] + game->block[1];
	else
		inc[1] = pos[1];
	if (cos(ray->ang) > 0)
		inc[0] = pos[0] + game->block[0];
	else
		inc[0] = pos[0];
	rayh[1] = inc[1];
	rayv[0] = inc[0];
	if (sin(ray->ang) > 0)
		rayh[0] = fabs(inc[1] - game->pos[1]) / tan(ray->ang) + game->pos[0];
	else
		rayh[0] = -fabs(inc[1] - game->pos[1]) / tan(ray->ang) + game->pos[0];
	if (cos(ray->ang) > 0)
		rayv[1] = fabs(inc[0] - game->pos[0]) * tan(ray->ang) + game->pos[1];
	else
		rayv[1] = -fabs(inc[0] - game->pos[0]) * tan(ray->ang) + game->pos[1];
	extend_ray(game, ray, rayh, rayv);
}

void render_rays(t_ray *rays, t_game *game)
{
	int i;
	int color;
	int pos[2];
	int ray[2];
	int top[2];
	int down[2];

	pos[0] = (int)game->pos[0];
	pos[1] = (int)game->pos[1];
	i = 0;
	color = 0;
	while (i <= WIN_W)
	{
		ray[0] = (int)rays[i].ray[0];
		ray[1] = (int)rays[i].ray[1];
		if (rays[i].e_side == N)
			color = 0x0000FF;
		else if (rays[i].e_side == S)
			color = 0xFF0000;
		else if (rays[i].e_side == E)
			color = 0x00FF00;
		else if (rays[i].e_side == W)
			color = 0x000000;
		rays[i].dist = fget_dist(game->pos, rays[i].ray) * cos(fabs(rays[i].ang - game->dir));
		top[0] = i;
		// this 64 can be replaced by the hight dezired for the wall
		top[1] = game->split - ((WIN_H   * (64))/ rays[i].dist);
		down[0] = i;
		down[1] = game->split + ((WIN_H  * (64))/ rays[i].dist);
		//draw_line_v2(game, ray, pos, color);
		draw_line_v2(game, top, down, color);
		i++;
	}
}

void caster(t_game *game)
{
	t_ray *ray;
	double deg;
	double inc;
	int pos[2];
	int idx;

	inc = (M_PI / 3) / WIN_W;
	ray = (t_ray *)malloc(sizeof(t_ray) * (WIN_W + 1));
	if (!ray)
		exit(EXIT_FAILURE);
	pos[0] = floor(game->pos[0] / game->block[0]) * game->block[0];
	pos[1] = floor(game->pos[1] / game->block[1]) * game->block[1];
	deg = game->dir - M_PI / 6;
	idx = 0;
	while (deg <= game->dir + M_PI / 6)
	{
		ray[idx].ang = deg;
		cast_one(game, pos, &ray[idx]);
		deg += inc;
		idx++;
	}
	ray[WIN_W].ang = game->dir + M_PI / 6;
	cast_one(game, pos, &ray[WIN_W]);
	render_rays(ray, game);
}
