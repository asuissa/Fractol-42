/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:53:30 by asuissa           #+#    #+#             */
/*   Updated: 2019/03/10 18:43:41 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_variables(t_fractol *e)
{
	if (!ft_strcmp(e->fractale, "mandelbrot") ||
		!ft_strcmp(e->fractale, "shuriken"))
	{
		e->v.x1 = -2.1;
		e->v.y1 = -1.2;
		e->v.max = 50;
		e->v.p = 0;
	}
	if (!ft_strcmp(e->fractale, "julia"))
	{
		e->v.x1 = -1;
		e->v.y1 = -1.2;
		e->v.c_reel = 0.285;
		e->v.c_imaginaire = 0.01;
		e->v.max = 150;
		e->v.p = 1;
	}
	e->v.image_x = -1;
	e->v.image_y = -1;
	e->v.x2 = WIN_WIDTH / e->v.zoom + e->v.x1;
	e->v.xdiff = e->v.x2 - e->v.x1;
	e->v.y2 = WIN_HEIGHT / e->v.zoom + e->v.y1;
	e->v.ydiff = e->v.y2 - e->v.y1;
	e->v.x1 -= e->v.xdiff / 8;
	e->v.y1 -= e->v.ydiff / 5;
}

void	mandelbrot(t_fractol *e)
{
	e->v.c_reel = e->v.x / e->v.zoom + e->v.x1;
	e->v.c_imaginaire = e->v.y / e->v.zoom + e->v.y1;
	e->v.z_reel = 0;
	e->v.z_imaginaire = 0;
	e->v.i = -1;
	while ((e->v.z_reel * e->v.z_reel + e->v.z_imaginaire * e->v.z_imaginaire)
		< 4 && ++e->v.i < e->v.max)
	{
		e->v.tmp = e->v.z_reel;
		e->v.z_reel = e->v.z_reel * e->v.z_reel
			- e->v.z_imaginaire * e->v.z_imaginaire + e->v.c_reel;
		e->v.z_imaginaire = 2 * e->v.z_imaginaire
			* e->v.tmp + e->v.c_imaginaire;
	}
	if (e->v.i != e->v.max)
		e->img.data[(int)e->v.image_w * (int)e->v.y + (int)e->v.x] =
			e->v.i * 255 * 255 / e->v.max;
}

void	shuriken(t_fractol *e)
{
	e->v.c_reel = e->v.x / e->v.zoom + e->v.x1;
	e->v.c_imaginaire = e->v.y / e->v.zoom + e->v.y1;
	e->v.z_reel = 0;
	e->v.z_imaginaire = 0;
	e->v.i = -1;
	while ((e->v.z_reel * e->v.z_reel + e->v.z_imaginaire * e->v.z_imaginaire)
		< 4 && ++e->v.i < e->v.max)
	{
		e->v.tmp = e->v.z_reel;
		e->v.z_reel = e->v.z_reel * e->v.z_reel
			- e->v.z_imaginaire * e->v.z_imaginaire + e->v.c_reel;
		e->v.z_imaginaire = -(2 * e->v.z_imaginaire * e->v.tmp)
			+ e->v.c_imaginaire;
	}
	if (e->v.i != e->v.max)
		e->img.data[(int)e->v.image_w * (int)e->v.y + (int)e->v.x] =
			e->v.i * 255 * 255 / e->v.max;
}

void	julia(t_fractol *e)
{
	e->v.z_reel = e->v.x / e->v.zoom + e->v.x1;
	e->v.z_imaginaire = e->v.y / e->v.zoom + e->v.y1;
	e->v.i = 0;
	while (e->v.z_reel * e->v.z_reel + e->v.z_imaginaire * e->v.z_imaginaire
		< 4 && e->v.i < e->v.max)
	{
		e->v.tmp = e->v.z_reel;
		e->v.z_reel = e->v.z_reel * e->v.z_reel - e->v.z_imaginaire
			* e->v.z_imaginaire + e->v.c_reel;
		e->v.z_imaginaire = 2 * e->v.z_imaginaire * e->v.tmp
			+ e->v.c_imaginaire;
		e->v.i++;
	}
	if (e->v.i != e->v.max)
		e->img.data[(int)e->v.image_w * (int)e->v.y + (int)e->v.x] =
			e->v.i * 255 * 255 / e->v.max;
}

void	init_fractale(t_fractol *e)
{
	e->v.image_w = (e->v.x2 - e->v.x1) * e->v.zoom;
	e->v.image_h = (e->v.y2 - e->v.y1) * e->v.zoom;
	e->img.img = mlx_new_image(e->mlx, e->v.image_w, e->v.image_h * 1.1);
	e->img.data = (int *)mlx_get_data_addr(e->img.img, &e->img.tmp,
		&e->img.tmp, &e->img.tmp);
	e->v.x = e->v.image_x + 1;
	while (++e->v.x < e->v.image_w + e->v.image_x)
	{
		e->v.y = e->v.image_y + 1;
		while (++e->v.y < e->v.image_h + e->v.image_y)
		{
			if (!ft_strcmp(e->fractale, "mandelbrot"))
				mandelbrot(e);
			if (!ft_strcmp(e->fractale, "julia"))
				julia(e);
			if (!ft_strcmp(e->fractale, "shuriken"))
				shuriken(e);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
}
