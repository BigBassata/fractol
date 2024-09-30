/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:53:49 by licohen           #+#    #+#             */
/*   Updated: 2024/09/30 22:59:06 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int mouse_events(int button, int x, int y, t_fractal *fractal)
// {
//     if (button == 4)
//     {
//         zoom(fractal, ZOOM_IN);
//         zoom_in_follow(fractal, x, y);
//     }
//     else if (button == 5)
//         zoom(fractal, ZOOM_OUT);
//     else
//         return (0);
//     mlx_destroy_image(fractal->disp, fractal->img.img);
//     render(fractal);
//     return (0);
// }

// void zoom_in_follow(t_fractal *fractal, int x, int y)
// {
//     if (x < WIDTH / 2)
//     {
//         fractal->vars.x_min -= (((WIDTH / 2) - x) / (WIDTH / 2))
//             * fractal->vars.dist_x;
//         fractal->vars.x_max -= (((WIDTH / 2) - x) / (WIDTH / 2))
//             * fractal->vars.dist_x;
//     }
//     else if (x > WIDTH / 2)
//     {
//         fractal->vars.x_min += ((x - (WIDTH / 2)) / (double)x) * fractal->vars.dist_x;
//         fractal->vars.x_max += ((x - (WIDTH / 2)) / (double)x) * fractal->vars.dist_x;
//     }
//     if (y < HEIGHT / 2)
//     {
//         fractal->vars.y_min -= (((HEIGHT / 2) - y) / (HEIGHT / 2))
//             * fractal->vars.dist_y;
//         fractal->vars.y_max -= (((HEIGHT / 2) - y) / (HEIGHT / 2))
//             * fractal->vars.dist_y;
//     }
//     else if (y > HEIGHT / 2)
//     {
//         fractal->vars.y_min += (((y - (HEIGHT / 2))) / (double)y) * fractal->vars.dist_y;
//         fractal->vars.y_max += (((y - (HEIGHT / 2))) / (double)y) * fractal->vars.dist_y;
//     }
// }

// int key_release(int keysym, t_fractal *fractal)
// {
//     if (keysym == XK_Escape)
//         quit(fractal);
//     return (0);
// }

// int key_press(int keysym, t_fractal *fractal)
// {
//     if (keysym == XK_Right || keysym == XK_Left
//         || keysym == XK_Down || keysym == XK_Up)
//         move(keysym, fractal);
//     else if (keysym == XK_plus)
//         zoom(fractal, ZOOM_IN);
//     else if (keysym == XK_minus)
//         zoom(fractal, ZOOM_OUT);
//     else if (keysym == XK_r)
//         fractal->color_def += RED;
//     else if (keysym == XK_g)
//         fractal->color_def += GREEN;
//     else if (keysym == XK_b)
//         fractal->color_def += BLUE;
//     else if (keysym == XK_i)
//         fractal->iter += 25;
//     else
//         return (0);
//     mlx_destroy_image(fractal->disp, fractal->img.img);
//     render(fractal);
//     return (0);
// }

// void move(int keysym, t_fractal *fractal)
// {
//     if (keysym == XK_Right)
//     {
//         fractal->vars.x_min += fractal->vars.dist_x / 5;
//         fractal->vars.x_max += fractal->vars.dist_x / 5;
//     }
//     else if (keysym == XK_Left)
//     {
//         fractal->vars.x_min -= fractal->vars.dist_x / 5;
//         fractal->vars.x_max -= fractal->vars.dist_x / 5;
//     }
//     else if (keysym == XK_Up)
//     {
//         fractal->vars.y_max -= fractal->vars.dist_y / 5;
//         fractal->vars.y_min -= fractal->vars.dist_y / 5;
//     }
//     else if (keysym == XK_Down)
//     {
//         fractal->vars.y_max += fractal->vars.dist_y / 5;
//         fractal->vars.y_min += fractal->vars.dist_y / 5;
//     }
// }

int mouse_events(int button, int x, int y, t_fractal *fractal)
{
    (void)x;
    (void)y;
    if (button == 4)
        zoom(fractal, ZOOM_IN);
    else if (button == 5)
        zoom(fractal, ZOOM_OUT);
    else
        return (0);
    mlx_destroy_image(fractal->disp, fractal->img.img);
    render(fractal);
    return (0);
}

int key_release(int keysym, t_fractal *fractal)
{
    if (keysym == XK_Escape)
        quit(fractal);
    return (0);
}

int key_press(int keysym, t_fractal *fractal)
{
    if (keysym == XK_Right || keysym == XK_Left
        || keysym == XK_Down || keysym == XK_Up)
        move(keysym, fractal);
    else if (keysym == XK_Escape)
        quit(fractal);
    else
        return (0);
    mlx_destroy_image(fractal->disp, fractal->img.img);
    render(fractal);
    return (0);
}

void move(int keysym, t_fractal *fractal)
{
    if (keysym == XK_Right)
    {
        fractal->vars.x_min += fractal->vars.dist_x / 5;
        fractal->vars.x_max += fractal->vars.dist_x / 5;
    }
    else if (keysym == XK_Left)
    {
        fractal->vars.x_min -= fractal->vars.dist_x / 5;
        fractal->vars.x_max -= fractal->vars.dist_x / 5;
    }
    else if (keysym == XK_Up)
    {
        fractal->vars.y_max -= fractal->vars.dist_y / 5;
        fractal->vars.y_min -= fractal->vars.dist_y / 5;
    }
    else if (keysym == XK_Down)
    {
        fractal->vars.y_max += fractal->vars.dist_y / 5;
        fractal->vars.y_min += fractal->vars.dist_y / 5;
    }
}