/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:34:19 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/26 19:46:43 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"
#include "../../inc/parser.h"

char	*get_color_value(char *str, int *idx)
{
	int		len;
	char	*start;

	len = 0;
	while (str && str[*idx] && (str[*idx] == ' ' || str[*idx] == '\t'))
		*idx = *idx + 1;
	if (str[*idx] == ',' && *idx != 0)
		*idx = *idx + 1;
	while (str && str[*idx] && (str[*idx] == ' ' || str[*idx] == '\t'))
		*idx = *idx + 1;
	start = str + *idx;
	while (str && str[*idx] && str[*idx] != ',' && \
	str[*idx] != ' ' && str[*idx] != '\t')
	{
		if (str[*idx] < '0' || str[*idx] > '9')
			return (NULL);
		len++;
		*idx = *idx + 1;
	}
	if (len < 1)
		return (NULL);
	return (ft_substr(start, str + *idx));
}

static void	long_color_error(char **error, char	**line)
{
	if (ft_strlen(line[0]) > 3)
		*error = ft_strdup(line[0]);
	if (!*error && ft_strlen(line[1]) > 3)
		*error = ft_strdup(line[1]);
	if (!*error && ft_strlen(line[2]) > 3)
		*error = ft_strdup(line[2]);
}

static int	parser_get_color(int *color, char *str, char **error)
{
	int		i;
	int		rgb[3];
	char	*line[3];

	i = 0;
	line[0] = get_color_value(str, &i);
	line[1] = get_color_value(str, &i);
	line[2] = get_color_value(str, &i);
	if (line[0] && ft_strlen(line[0]) < 4)
		rgb[0] = ft_atoi(line[0]);
	if (line[1] && ft_strlen(line[1]) < 4)
		rgb[1] = ft_atoi(line[1]);
	if (line[2] && ft_strlen(line[2]) < 4)
		rgb[2] = ft_atoi(line[2]);
	long_color_error(error, line);
	if (*error || !line[0] ||!line[1] ||!line[2] || str[i])
		return (free(line[0]), free(line[1]), free(line[2]), str[i]);
	if (rgb[0] > 255)
		return (free(line[0]), free(line[1]), free(line[2]), rgb[0]);
	if (rgb[1] > 255)
		return (free(line[0]), free(line[1]), free(line[2]), rgb[1]);
	if (rgb[2] > 255)
		return (free(line[0]), free(line[1]), free(line[2]), rgb[2]);
	*color = rgb[0] << 16 | rgb[1] << 8 | rgb[2];
	return (free(line[0]), free(line[1]), free(line[2]), 0);
}

static int	parser_color_error(char *str, char *errorstr, int error, int exits)
{
	if (errorstr || error)
	{
		if (!exits)
			return (1);
		write(2, "\033[31mError: Invalid color value : \x1B[35m", 40);
		write(2, str, ft_strlen(str));
		write(2, "\033[31m : \033[33m", 14);
	}
	if (errorstr)
		write(2, errorstr, ft_strlen(errorstr));
	else if (error > 255)
		ft_putnbr_fd(error, 2);
	else if (error)
		write(2, &error, 1);
	if (errorstr || error)
		write(2, "\n\033[0m", 6);
	if (errorstr)
		free(errorstr);
	if (errorstr || error)
		exit(2);
	return (0);
}

void	parser_color(t_cub *cub)
{
	int		error;
	char	*errorstr;

	errorstr = NULL;
	error = parser_get_color(&(cub->c_color), cub->c, &errorstr);
	parser_color_error("Ceilling color", errorstr, error, 1);
	errorstr = NULL;
	error = parser_get_color(&(cub->f_color), cub->f, &errorstr);
	parser_color_error("Floor color", errorstr, error, 1);
}
