/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:49:04 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/27 19:07:08 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"
#include "../../inc/parser.h"

void	parse_map(char	*file, t_cub *cub)
{
	int	fd;
	int	i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	count_map_lines(cub, fd);
	close(fd);
	cub->map = (char **)malloc(sizeof(char *) * (cub->map_height + 2));
	if (!cub->map)
		exit(3);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	fill_map(cub, fd);
	refill_map(cub);
	i = -1;
	while (++i < cub->map_height)
	{
		printf("||%s||\n", cub->map[i]);
	}
	//exit(0);
}

void	count_map_lines(t_cub *cub, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (++i< 7)
	{
		line = skip_empty_lines(fd);
		free(line);
	}
	if (!line)
		i = 0;
	line = skip_empty_lines(fd);
	while (line && i++)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	cub->map_height = i - 7;
	if (cub->map_height >= 0)
		return ;
	write(2, "\033[31mError: Map not found\n\033[0m", 31);
}

void	fill_map(t_cub *cub, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (++i< 7)
	{
		line = skip_empty_lines(fd);
		free(line);
	}
	cub->map[1] = skip_empty_lines(fd);
	cub->map_width = ft_strlen(cub->map[1]);
	i = 1;
	while (++i < cub->map_height + 2)
	{
		cub->map[i] = get_next_line(fd);
		if (cub->map_width < ft_strlen(cub->map[i]))
		{
			cub->map_width = ft_strlen(cub->map[i]);
			if (i == cub->map_height - 1)
				cub->map_width += 1;
		}
	}
	close(fd);
}

static void	refill_map_part(t_cub *cub)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (++i <= cub->map_height)
	{
		j = -1;
		line = malloc(sizeof(char) * cub->map_width + 2);
		line[0] = ' ';
		while (++j <= cub->map_width)
		{
			if (j < ft_strlen(cub->map[i]) && cub->map[i][j] != '\n')
				line[j + 1] = cub->map[i][j];
			else
				line[j + 1] = ' ';
		}
		line[j] = '\0';
		free(cub->map[i]);
		cub->map[i] = line;
	}
}

void	refill_map(t_cub *cub)
{
	int		j;
	char	*line;

	refill_map_part(cub);
	cub->map_width += 1;
	cub->map_height += 2;
	line = malloc(sizeof(char) * cub->map_width + 1);
	j = -1;
	while (++j < cub->map_width)
		line[j] = ' ';
	line[j] = '\0';
	cub->map[0] = line;
	cub->map[cub->map_height - 1] = ft_strdup(line);
}
