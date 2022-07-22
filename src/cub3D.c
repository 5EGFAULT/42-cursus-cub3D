/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:41:22 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/26 23:38:46 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parser.h"
#include "../inc/validator.h"
#include "../inc/game.h"

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc != 2)
		return (printf("Usage: ./cub3D <cubfile>\n"), 1);
	cub = parse_cub(argv[1]);
	if (!cub)
		return (0);
	validate_cub(cub);
	run_game(cub);
	//system("leaks cub3D");
	return (0);
}
