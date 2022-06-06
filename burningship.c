/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burninship.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:43:00 by cbourajl          #+#    #+#             */
/*   Updated: 2022/05/31 16:43:01 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	b_init(t_mlx *mlx)
{
	mlx->i = 0;
	mlx->j = 0;
	mlx->x = 0;
	mlx->y = 0;
	mlx->remin = -2;
	mlx->remax = 2;
	mlx->immin = -2;
	mlx->immax = 2;
	mlx->interpolation = 1.0;
	mlx->color = 0xEEEEEE;
	mlx->newcolor = 0xEEEEEE;
	mlx->ptr = mlx_init();
	mlx->type = 3;
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "burning ship");
	mlx->img_ptr = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->img_str = (int *)mlx_get_data_addr(mlx->img_ptr, \
			&(mlx->bpp), &(mlx->l), &(mlx->endian));
}

void	b_calcul(t_mlx *mlx, int x, int y)
{
	mlx->iter = 1;
	mlx->c.r = mlx->remin + (x + mlx->j) / WIDTH * (mlx->remax - mlx->remin);
	mlx->c.i = mlx->immin + (y + mlx->i) / HEIGHT * (mlx->immax - mlx->immin);
	mlx->z.r = 0.0;
	mlx->z.i = 0.0;
	mlx->tmp = mlx->z;
	while (mlx->z.r * mlx->z.r + mlx->z.i * mlx->z.i < 4 && mlx->iter < 100)
	{

		mlx->tmp.r =fabs(mlx->z.r) * fabs(mlx->z.r) - fabs(mlx->z.i) * fabs(mlx->z.i) + mlx->c.r;
		mlx->tmp.i = 2 * fabs(mlx->z.r) * fabs(mlx->z.i) + mlx->c.i;
		mlx->z = mlx->tmp;
		mlx->iter++;
	}
}

void	ft_draw_b(t_mlx	*mlx)
{
	int	y;
	int	x;

	y = -1;
	while (++y < (int)HEIGHT)
	{
		x = -1;
		while (++x < (int)WIDTH)
		{
			b_calcul(mlx, x, y);
			if (mlx->iter == MAX_ITER)
				mlx->color = mlx->newcolor;
			else
				mlx->color = mlx->newcolor * mlx->iter;
			mlx->img_str[((int)(WIDTH) * y) + x] = mlx->color;
		}
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_ptr, 0, 0);
}

void	ft_burningship(t_mlx *mlx)
{
	b_init(mlx);
	ft_draw_b(mlx);
}
