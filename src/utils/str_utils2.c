/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:33:02 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/26 14:36:36 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

static int	check_ft_set(char c, char const *set)
{
	int	i;
	int	exist;

	exist = 0;
	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
		{
			exist = 1;
			break ;
		}
	}
	return (exist);
}

static char	*fill_new_str(char const *s1, int start, int end)
{
	char	*news1;
	int		i;

	i = -1;
	news1 = (char *)malloc(end - start + 1);
	if (!news1)
		return (0);
	while (++i < end - start)
		news1[i] = s1[i + start];
	news1[end - start] = '\0';
	return (news1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;

	i = -1;
	if (!s1)
		return (0);
	if (!set || !set[0])
		return (ft_strdup(s1));
	while (s1[++i] && check_ft_set(s1[i], set))
		;
	start = i;
	end = ft_strlen(s1);
	i = end;
	while (--i > start && check_ft_set(s1[i], set))
		;
	end = i + 1;
	return (fill_new_str(s1, start, end));
}
