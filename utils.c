/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:29:45 by licohen           #+#    #+#             */
/*   Updated: 2024/09/30 22:39:40 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mlx_funcs(t_fractal *fractal)
{
    fractal->disp = mlx_init();
    if (fractal->disp == NULL)
        malloc_error("Error calling mlx_init\n", fractal);

    fractal->win = mlx_new_window(fractal->disp, WIDTH, HEIGHT, fractal->name);
    if (fractal->win == NULL)
        malloc_error("Error calling mlx_new_window\n", fractal);

    mlx_mouse_hook(fractal->win, mouse_events, fractal);
    mlx_key_hook(fractal->win, key_release, fractal);
    mlx_hook(fractal->win, KeyPress, KeyPressMask, key_press, fractal);
    mlx_hook(fractal->win, DestroyNotify, ButtonReleaseMask, quit, fractal);
    mlx_expose_hook(fractal->win, render, fractal);
    mlx_loop(fractal->disp);
}

void invalid_args(void)
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


void cleanup(t_fractal *fractal)
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