/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 21:01:32 by fmorales          #+#    #+#             */
/*   Updated: 2014/01/19 21:13:30 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "wolf3d.h"

void	pixel_put_to_image_down(t_image *t, int y, int h, int color)
{
	int	c;
	int	i;
	int	z;

	i = 0;
	while (i < h)
	{
		c = 0;
		while (c < (t->bpp / 8))
		{
			z = y + (i * t->sizeline);
			t->img[(c + z) / 4] = color;
			++c;
		}
		++i;
	}
}

void	pixel_put_to_image(t_image *t, int x, int color)
{
	int	i;
	int	h;
	int	c;
	int	y;
	int	z;

	h = (HEIGHT / (2 * t->k));
	y = ((HEIGHT / 2) * t->sizeline) + (x * t->bpp / 8);
	i = 0;
	while (i < h)
	{
		c = 0;
		while (c < (t->bpp / 8))
		{
			z = y - (i * t->sizeline);
			t->img[(c + z) / 4] = color;
			++c;
		}
		++i;
	}
	pixel_put_to_image_down(t, y, h, color);
}
