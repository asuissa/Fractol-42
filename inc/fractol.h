/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:53:03 by asuissa           #+#    #+#             */
/*   Updated: 2019/03/10 14:29:56 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "../libft/libft.h"

# define WIN_WIDTH	800
# define WIN_HEIGHT	800
# define ZOOM		150

/*
**	Touche
*/

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_P 35
# define KEY_SPACE 49
# define KEY_OPEN 33
# define KEY_CLOSE 30
# define KEY_ESCAPE 53
# define KEY_PLUS 69
# define KEY_MINUS 78

/*
**	variables
*/

typedef struct		s_var
{
	int		x;
	int		y;
	double	x1;
	double	x2;
	double	xdiff;
	double	y1;
	double	y2;
	double	ydiff;
	double	c_reel;
	double	c_imaginaire;
	double	z_reel;
	double	z_imaginaire;
	int		i;
	double	tmp;
	double	zoom;
	int		max;
	double	image_w;
	double	image_h;
	int		image_x;
	int		image_y;
	int		p;
}					t_var;

/*
** img params ()
*/

typedef struct		s_data
{
	void	*img;
	int		*data;
	int		tmp;
	int		x;
	int		y;
}					t_data;

/*
**	mouse mvm params
*/

typedef struct		s_mouse
{
	int		x;
	int		y;
	int		x_mid;
	int		y_mid;
}					t_mouse;

typedef struct		s_fractol
{
	void		*mlx;
	void		*win;
	char		*fractale;
	t_data		img;
	t_var		v;
	t_mouse		mouse;
}					t_fractol;

/*
**	event.c
*/

void				move_img(t_fractol *e, t_data *black_screen,
	int dx, int dy);
int					key_hook(int keycode, t_fractol *e);
int					mouse_hook(int button, int x, int y, void *param);
void				zoomer(t_fractol *mlx, t_data *black_screen, double value);
void				change_screen(t_fractol *mlx, t_data *e);
int					mouse_mvm(int x, int y, t_fractol *e);

/*
**	cleaners.c
*/

void				clean_exit(void);
void				clean_screen(t_fractol *mlx, t_data *e);

/*
**	algos.c
*/

void				init_variables(t_fractol *e);
void				mandelbrot(t_fractol *e);
void				julia(t_fractol *e);
void				shuriken(t_fractol *e);
void				init_fractale(t_fractol *e);

/*
**	fdf.c
*/

void				init_mlx(t_fractol e);

#endif
