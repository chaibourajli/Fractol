/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:19:59 by cbourajl          #+#    #+#             */
/*   Updated: 2022/05/31 18:20:00 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double interpolate(double start, double end, double i)
{
    return (start + ((end - start) * i));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
		&& (unsigned char)s1[i] && (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}

void	checker(t_mlx *mlx)
{
	if (mlx->type == 1)
		ft_draw_m(mlx);
	else if (mlx->type == 2)
		ft_draw_j(mlx);
	else if (mlx->type == 3)
		ft_draw_b(mlx);
}
