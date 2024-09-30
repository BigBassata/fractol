/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niarefi <niarefi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:32:48 by niarefi           #+#    #+#             */
/*   Updated: 2024/05/27 15:50:01 by niarefi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	long		nb;
	char		*dst;

	nb = (long)n;
	len = ft_len(nb);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	if (nb < 0)
	{
		dst[0] = '-';
		nb = -nb;
	}
	dst[len] = '\0';
	if (nb == 0)
		dst[0] = 48;
	len--;
	while (nb > 0)
	{
		dst[len] = (nb % 10) + 48;
		nb /= 10;
		len--;
	}
	return (dst);
}
