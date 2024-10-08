/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:29:45 by licohen           #+#    #+#             */
/*   Updated: 2024/10/08 14:01:19 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	invalid_args(void)
{
	ft_putstr_fd("Invalid arguments\n", 2);
	ft_putstr_fd("Usage:\n", 2);
	ft_putstr_fd("./fractol julia [real] [imaginary]\n", 2);
	ft_putstr_fd("./fractol mandelbrot\n", 2);
	ft_putstr_fd("./fractol fern\n", 2);
	exit(1);
}

void	malloc_error(char *str, t_fractal *fractal)
{
	ft_putstr_fd(str, 2);
	cleanup(fractal);
	exit(1);
}

void	cleanup(t_fractal *fractal)
{
	if (fractal->disp)
	{
		if (fractal->img.img)
			mlx_destroy_image(fractal->disp, fractal->img.img);
		if (fractal->win)
			mlx_destroy_window(fractal->disp, fractal->win);
		mlx_destroy_display(fractal->disp);
		free(fractal->disp);
	}
}

int	quit(t_fractal *fractal)
{
	cleanup(fractal);
	exit(0);
}
