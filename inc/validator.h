/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:54:03 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/26 20:07:47 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATOR_H
# define VALIDATOR_H
# include <fcntl.h>
# include <errno.h>
# include "cub3D.h"

void	validate_file_name(char *file);
void	validate_cub(t_cub *cub);
void	validator_obj(t_cub *cub);
void	validator_player(t_cub *cub);
void	validator_closed(t_cub *cub);
void	validator_file(char *file);
void	validate_conf_files(t_cub *cub);

#endif