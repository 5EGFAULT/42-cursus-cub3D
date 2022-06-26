/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:55:50 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/26 15:48:42 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"
#include "../../inc/parser.h"

char	*skip_empty_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && (ft_strlen(line) == 0 || *line == '\n'))
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

void	check_conf(t_cub *cub)
{
	int	error;

	error = 0;
	if (!cub->no || !cub->so || !cub->we || !cub->ea || !cub->f || !cub->c)
	{
		write(2, "\033[31mError: Missing required key : \033[33m", 41);
		if (!cub->no)
			write(2, " NO ", 5);
		if (!cub->so)
			write(2, " SO ", 5);
		if (!cub->we)
			write(2, " WE ", 5);
		if (!cub->ea)
			write(2, " EA ", 5);
		if (!cub->f)
			write(2, " F ", 4);
		if (!cub->c)
			write(2, " C ", 4);
		write(2, "\n\033[0m\n", 7);
		exit(2);
	}
}

char	*get_color_value(char *str, int *idx)
{
	int len;

	str += *idx;
	while (*str && (*str == ',' || *str == ' ' || *str == '\t'))
		str++;
	len = 0;
	while (str && str[*idx])
	{
		if (str[*idx] < '0' || str[*idx] > '9')
			return (NULL);
		*idx += 1;
		len++;
	}
	if (len > 3 || len < 1)
		return (NULL);
	return (ft_substr(str, str + *idx));
}

void	parser_color(t_cub *cub)
{
	int		i;
	int		rgb[3];
	char	*line;

	(void)rgb;
	(void)cub;
	i = 0;
	line = get_color_value(cub->c, &i);
	printf("{%s}=>%s\n", cub->c,line);
}
