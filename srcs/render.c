/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:51:42 by licohen           #+#    #+#             */
/*   Updated: 2024/10/07 17:22:05 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render(t_fractal *fractal)
{
	int	x;
	int	y;

	fractal->img.img = mlx_new_image(fractal->disp, WIDTH, HEIGHT);
	if (fractal->img.img == NULL)
		malloc_error("Error calling mlx_new_image\n", fractal);
	fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bpp,
			&fractal->img.line_len, &fractal->img.endian);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			render_pixel(fractal, x, y);
	}
	mlx_put_image_to_window(fractal->disp, fractal->win, fractal->img.img, 0,
		0);
	return (0);
}

int	render_pixel(t_fractal *fractal, int x, int y)
{
	int		index;
	double	scaled_x;
	double	scaled_y;

	scaled_x = (x * (fractal->vars.dist_x / WIDTH)) + fractal->vars.x_min;
	scaled_y = (y * (fractal->vars.dist_y / HEIGHT)) + fractal->vars.y_min;
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		julia(scaled_x, scaled_y, fractal);
	}
	else if (!ft_strncmp(fractal->name, "mandelbrot", 10))
	{
		mandelbrot(scaled_x, scaled_y, fractal);
	}
	index = y * fractal->img.line_len + x * (fractal->img.bpp / 8);
	*((unsigned int *)(fractal->img.addr + index)) = fractal->color;
	return (0);
}
