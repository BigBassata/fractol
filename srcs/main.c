/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 01:30:42 by licohen           #+#    #+#             */
/*   Updated: 2024/10/07 15:28:46 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	ft_memset(&fractal, 0, sizeof(fractal));
	if ((argc == 4 && !ft_strncmp(argv[1], "julia", 5)) || (argc == 2
			&& (!ft_strncmp(argv[1], "mandelbrot", 10))) || (argc == 2
			&& (!ft_strncmp(argv[1], "fern", 4))))
	{
		if (!ft_strncmp(argv[1], "julia", 5))
		{
			if (ft_countchr(argv[2], '.') > 1 || ft_countchr(argv[3], '.') > 1)
				invalid_args();
			set_julia(&fractal, argv[2], argv[3], argv[1]);
		}
		else if (!ft_strncmp(argv[1], "mandelbrot", 10))
			set_mandelbrot(&fractal, argv[1]);
		mlx_funcs(&fractal);
		cleanup(&fractal);
		return (0);
	}
	invalid_args();
}
