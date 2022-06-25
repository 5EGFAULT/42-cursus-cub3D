/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:29:31 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/25 16:28:31 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 32

char	*get_next_line(int fd);
int		gnl_ft_strlen(char *str);
char	*gnl_ft_substr(char *str, char *end);
char	*gnl_ft_strchr(char *str);
char	*gnl_ft_strjoin(char *s1, char *s2);

#endif
