/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:42:54 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/25 18:46:25 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <fcntl.h>
# include <errno.h>
# include "cub3D.h"
# include "get_next_line.h"

t_cub	*init_cub(void);
t_cub	*parse_cub(char *file);

void	validate_file_name(char *file);

void	parse_conf(char	*file, t_cub *cub);
void	set_conf_value(t_cub *cub, char	*key, char *value);
char	**get_conf_dest(t_cub *cub, char *key);
char	*get_key(char *line);
char	*get_value(char *line, int len_key);
char	*skip_empty_lines(int fd);
void	check_conf(t_cub *cub);

#endif