/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niarefi <niarefi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:49:29 by niarefi           #+#    #+#             */
/*   Updated: 2024/05/27 20:17:33 by niarefi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	i;
	char	*ds;

	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (start + len > slen)
		len = slen - start;
	ds = malloc(sizeof(char) * (len + 1));
	if (!ds)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		ds[i] = s[start + i];
		i++;
	}
	ds[i] = '\0';
	return (ds);
}
