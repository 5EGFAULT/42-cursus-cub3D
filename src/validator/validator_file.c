/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:06:52 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/26 15:09:27 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"
#include "../../inc/validator.h"

void	validator_file(char *file)
{
	char	*error;
	int		fd;

	fd = open(file, O_RDONLY);
	error = NULL;
	if (fd == -1 && errno == EACCES)
		error = "\033[31mError: Permission denied : \033[33m";
	else if (fd == -1)
		error = "\033[31mError: File not found : \033[33m";
	(fd >= 0) && close(fd);
	if (error)
	{
		write(2, error, ft_strlen(error));
		write(2, file, ft_strlen(file));
		write(2, "\n\033[0m", 6);
		exit(2);
	}
}
