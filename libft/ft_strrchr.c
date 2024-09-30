/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niarefi <niarefi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:50:06 by niarefi           #+#    #+#             */
/*   Updated: 2024/05/31 17:53:07 by niarefi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ss;

	i = 0;
	ss = 0;
	while (s[i])
	{
		if (s[i] == (const char)c)
			ss = (char *)s + i;
		i++;
	}
	if ((char)c == '\0')
		ss = (char *)(s + i);
	return (ss);
}
