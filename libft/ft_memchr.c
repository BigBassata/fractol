/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niarefi <niarefi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:52:48 by niarefi           #+#    #+#             */
/*   Updated: 2024/05/22 13:16:10 by niarefi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*ss;

	i = 0;
	ss = (const unsigned char *)s;
	while (i < n)
	{
		if (ss[i] == (const unsigned char)c)
			return ((void *)&ss[i]);
		i++;
	}
	return (NULL);
}
