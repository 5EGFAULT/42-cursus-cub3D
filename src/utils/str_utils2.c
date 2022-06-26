/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:33:02 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/26 18:37:08 by asouinia         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	sign = 1;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		++i;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + str[i++] - '0';
	return (sign * nbr);
}
