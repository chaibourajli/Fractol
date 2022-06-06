/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:42:45 by cbourajl          #+#    #+#             */
/*   Updated: 2022/05/31 16:42:47 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

#define MAX_ITER 100
#define WIDTH 500.
#define HEIGHT 500.
#define COLORA 0xFFE162
#define COLORB 0xFF6464
#define COLORC 0x91C483

typedef struct complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_mlx{
	void		*ptr;
	void		*win;
	void		*img_ptr;
	int			*img_str;
	int			bpp;
	int			l;
	int			endian;
	int			x;
	int			y;
	int			i;
	int			j;
	int			color;
	int			newcolor;
	int			iter;
	int			type;
	double		remin;
	double		remax;
	double		immin;
	double		immax;
	double		interpolation;
	t_complex	z;
	t_complex	tmp;
	t_complex	c;
}	t_mlx;

double	interpolate(double start, double end, double i);
int		ft_close(void *param);
int		mouse_move(int x, int y, void *param);
int		key_press(int keycode, void *param);
int		mouse_press(int button, int x, int y, t_mlx *mlx);
int		ft_strcmp(const char *s1, const char *s2);
void	m_init(t_mlx *mlx);
void	m_calcul(t_mlx *mlx, int x, int y);
void	ft_draw_m(t_mlx	*mlx);
void	ft_mandelbrot(t_mlx *mlx);
void	ft_clear_image(t_mlx *mlx);
void	ft_putstr(char *s);
void	ft_draw_j(t_mlx	*mlx);
void	checker(t_mlx *mlx);
void	ft_julia(t_mlx *mlx);
void	j_calcul(t_mlx *mlx, int x, int y);
void	j_init(t_mlx *mlx);
void	checker(t_mlx *mlx);
void	ft_burningship(t_mlx *mlx);
void	ft_draw_b(t_mlx	*mlx);
void	b_calcul(t_mlx *mlx, int x, int y);
void	b_init(t_mlx *mlx);
void	menu(void);

#endif
