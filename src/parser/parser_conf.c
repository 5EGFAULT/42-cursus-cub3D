/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_conf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:00:22 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/25 19:01:44 by asouinia         ###   ########.fr       */
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
	while (line && i++ < 6)
	{
		line[ft_strlen(line) - 1] = '\0';
		pair[0] = get_key(line);
		if (pair[0][0] == '1' || pair[0][0] == '0')
			break ;
		pair[1] = get_value(line, ft_strlen(pair[0]));
		set_conf_value(cub, pair[0], pair[1]);
		free(line);
		line = skip_empty_lines(fd);
	}
	close(fd);
	free(line);
	check_conf(cub);
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
	free(key);
	free(value);
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
