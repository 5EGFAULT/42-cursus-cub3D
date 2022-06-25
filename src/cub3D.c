/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:41:22 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/25 19:02:18 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parser.h"

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc != 2)
		return (printf("Usage: ./cub3D <cubfile>\n"), 1);
	cub = parse_cub(argv[1]);
	if (!cub)
		return (0);
	return (0);
}
