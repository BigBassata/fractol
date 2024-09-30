/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niarefi <niarefi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:57:49 by niarefi           #+#    #+#             */
/*   Updated: 2024/05/27 19:55:16 by niarefi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischarset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		s;
	int		e;
	int		i;

	i = 0;
	s = 0;
	e = ft_strlen(s1);
	while (s1[s] && ft_ischarset(s1[s], set))
		s++;
	while (e > s && ft_ischarset(s1[e - 1], set))
		e--;
	str = (char *)malloc(sizeof(char) * (e - s + 1));
	if (!str)
		return (NULL);
	while (s < e)
		str[i++] = s1[s++];
	str[i] = '\0';
	return (str);
}
