/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:49:04 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/25 22:34:38 by asouinia         ###   ########.fr       */
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
	cub->map = (char **)malloc(sizeof(char *) * cub->map_height);
	if (!cub->map)
		exit(3);
	close(fd);
	fill_map(file, cub);
	refill_map(cub);
	i = -1;
	while (++i < cub->map_height)
	{
		printf("%s\n", cub->map[i]);
	}
}

void	count_map_lines(t_cub *cub, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i++ < 7)
	{
		line = skip_empty_lines(fd);
		free(line);
	}
	if (!line)
		i = 0;
	line = get_next_line(fd);
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
	exit(2);
}

void	fill_map(char	*file, t_cub *cub)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	i = 0;
	while (i++ < 6)
	{
		line = skip_empty_lines(fd);
		free(line);
	}
	cub->map[0] = skip_empty_lines(fd);
	cub->map_width = ft_strlen(cub->map[0]);
	i = 0;
	while (++i < cub->map_height)
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

void	refill_map(t_cub *cub)
{
	int		i;
	int		j;
	char	*line;

	i = -1;
	while (++i < cub->map_height)
	{
		j = -1;
		line = malloc(sizeof(char) * cub->map_width + 1);
		while (++j < cub->map_width - 1)
		{
			if (j < ft_strlen(cub->map[i]) - 1 && cub->map[i][j] != '\n')
				line[j] = cub->map[i][j];
			else
				//line[j] = '*';
				line[j] = ' ';
			printf("%c", cub->map[i][j]);
		}
		printf("\n%s\n\n", cub->map[i]);
		line[j] = '\0';
		free(cub->map[i]);
		cub->map[i] = line;
	}
}