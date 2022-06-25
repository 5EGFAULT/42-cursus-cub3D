/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:31:32 by asouinia          #+#    #+#             */
/*   Updated: 2022/06/25 16:03:02 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

char	*ft_substr(char *str, char *end)
{
	char	*substr;
	int		i;

	if (!str || !*str)
		return (NULL);
	i = 0;
	while (str && str[i] && str + i != end)
		i++;
	substr = (char *)malloc(sizeof(char) * (i + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (str && str[i] && str + i != end)
	{
		substr[i] = str[i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s1);
	s2 = (char *) malloc(len + 1);
	if (s2)
		return ((char *)ft_memcpy(s2, s1, len + 1));
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (!dst && !src)
		return (NULL);
	while (++i < n)
	{
		*((unsigned char *)(dst + i)) = *((unsigned char *)(src + i));
	}
	return (dst);
}
