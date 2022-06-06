/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:43:22 by cbourajl          #+#    #+#             */
/*   Updated: 2022/05/31 16:43:24 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	menu(void)
{
	ft_putstr("Invalid number of arguments.\n");
	ft_putstr("    Please try again by choosing a fractal.\n");
	ft_putstr("For The Mandelbrot set,please enter 1.\n");
	ft_putstr("For Julia set,please enter 2.\n");
	ft_putstr("For The Burninship set,please enter 3.\n");
}

int	main(int ac, char **av)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (ac == 2)
	{
		if (!(ft_strcmp(av[1], "1")))
			ft_mandelbrot(mlx);
		else if (!(ft_strcmp(av[1], "2")))
			ft_julia(mlx);
		else if (!(ft_strcmp(av[1], "3")))
			ft_burningship(mlx);
		else
			return (ft_putstr("Please enter a valid number.\n"), 0);
		mlx_hook(mlx->win, 6, 0, mouse_move, (void *)mlx);
		mlx_hook(mlx->win, 4, 0, mouse_press, (void *)mlx);
		mlx_hook(mlx->win, 2, 0, key_press, (void *)mlx);
		mlx_hook(mlx->win, 17, 0, ft_close, (void *)mlx);
		mlx_loop(mlx->ptr);
	}
	else if (ac > 2)
		ft_putstr("Too many arguments. Please enter a number.\n");
	else
		menu();
	free(mlx);
	return (0);
}
