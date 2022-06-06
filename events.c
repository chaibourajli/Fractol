/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:19:59 by cbourajl          #+#    #+#             */
/*   Updated: 2022/05/31 18:20:00 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	ft_clear_image(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < (WIDTH*HEIGHT))
	{
		mlx->img_str[i] = 0x000000;
		i++;
	}
}

int ft_close(void *param)
{
	(void)param;
	exit(0);
	return 0;
}

int mouse_move(int x, int y, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)malloc((sizeof(t_mlx)));
	mlx = param;
	mlx->x = x;
	mlx->y = y;
	checker(mlx);
	return (0);
}

int key_press(int keycode, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)malloc((sizeof(t_mlx)));
	mlx = param;
	if(keycode == 53)
		exit(0);
	if(keycode == 126)
		mlx->i+=20;
	else if (keycode == 125)
		mlx->i-=20;
	else if (keycode == 123)
		mlx->j+=20;
	else if (keycode == 124)
		mlx->j-=20;
	if (keycode == 18)
		mlx->newcolor = COLORA;
	else if (keycode == 19)
		mlx->newcolor = COLORB;
		else if (keycode == 20)
		mlx->newcolor = COLORC;
	ft_clear_image(mlx);
	checker(mlx);
	return 0;
}

int mouse_press(int button, int x, int y,t_mlx *mlx)
{
	double mousre;
	double mouseim;

	mousre = (double)mlx->x / (WIDTH / (mlx->remax - mlx->remin)) + mlx->remin;
	mouseim = (double)mlx->y / (HEIGHT / (mlx->immax - mlx->immin)) + mlx->immin;
	x = 0;
	y = 0;
	if (button == 5)
		mlx->interpolation = 0.9;
	else if (button == 4)
		mlx->interpolation = 1.2;
	mlx->remin = interpolate(mousre, mlx->remin, mlx->interpolation);
	mlx->immin = interpolate(mouseim, mlx->immin, mlx->interpolation);
	mlx->remax = interpolate(mousre, mlx->remax, mlx->interpolation);
	mlx->immax = interpolate(mouseim, mlx->immax, mlx->interpolation);
	ft_clear_image(mlx);
	checker(mlx);
	return 0;
}
