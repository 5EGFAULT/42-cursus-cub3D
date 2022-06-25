/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_conf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:00:22 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/25 18:50:58 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"
#include "../../inc/parser.h"

void	parse_conf(char	*file, t_cub *cub)
{
	int		fd;
	int		i;
	char	*line;
	char	*pair[2];

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	line = skip_empty_lines(fd);
	while (line && i < 6)
	{
		line[ft_strlen(line) - 1] = '\0';
		pair[0] = get_key(line);
		if (pair[0][0] == '1' || pair[0][0] == '0')
			break ;
		pair[1] = get_value(line, ft_strlen(pair[0]));
		i++;
		printf("key={%s}\t\t", pair[0]);
		printf("value=|%s|\n", pair[1]);
		set_conf_value(cub, pair[0], pair[1]);
		free(line);
		line = skip_empty_lines(fd);
	}
	close(fd);
	check_conf(cub);
	(void)cub;
}

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

char	*get_key(char *line)
{
	char	*split[2];

	while (*line == ' ' || *line == '\t')
		line++;
	split[0] = ft_strchr(line, ' ');
	split[1] = ft_strchr(line, '\t');
	if (!split[0])
		split[0] = split[1];
	else if (split[1] < split[0] && split[1])
		split[0] = split[1];
	if (!split[0] && (!*line || *line == '\n'))
	{
		write(2, "\033[31mError: Found a non empty line\n\033[0m", 35);
		exit(2);
	}
	return (ft_substr(line, split[0]));
}

char	*get_value(char *line, int len_key)
{
	int	i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i += len_key;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\n')
		return (NULL);
	return (ft_substr(line + i, NULL));
}

void	set_conf_value(t_cub *cub, char	*key, char *value)
{
	char	**dest;
	char	*error;

	error = NULL;
	(void)cub;
	(void)key;
	(void)value;
	dest = get_conf_dest(cub, key);
	if (dest && !*dest && value)
		*dest = ft_strdup(value);
	else if (!dest)
		error = "\033[31mError: Invalid key : \033[33m";
	else if (dest && *dest)
		error = "\033[31mError: Duplicate key : \033[33m";
	else if (!value)
		error = "\033[31mError: Missing value for : \033[33m";
	if (error)
	{
		write(2, error, ft_strlen(error));
		write(2, key, ft_strlen(key));
		write(2, "\n\033[0m", 6);
		exit(2);
	}
}

char	**get_conf_dest(t_cub *cub, char *key)
{
	if (!ft_strncmp(key, "NO", 3))
		return (&cub->no);
	else if (!ft_strncmp(key, "SO", 3))
		return (&cub->so);
	else if (!ft_strncmp(key, "WE", 3))
		return (&cub->we);
	else if (!ft_strncmp(key, "EA", 3))
		return (&cub->ea);
	else if (!ft_strncmp(key, "F", 2))
		return (&cub->f);
	else if (!ft_strncmp(key, "C", 2))
		return (&cub->c);
	else
		return (NULL);
}

void	check_conf(t_cub *cub)
{
	int	error;

	error = 0;
	if (!cub->no || !cub->so || !cub->we || !cub->ea || !cub->f || !cub->c)
	{
		write(2, "\033[31mError: Missing required key : ", 36);
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