/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 20:57:38 by fmorales          #+#    #+#             */
/*   Updated: 2014/01/21 18:47:32 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <mlx.h>
#include "wolf3d.h"

float		raycast(t_image *t, float x1, float y1, int *color)
{
	int		x;
	int		y;
	float	k;

	k = 1;
	x = t->x + (k * (x1 - t->x));
	y = t->y + (k * (y1 - t->y));
	while (t->lab[x][y] == 0)
	{
		x = t->x + (k * (x1 - t->x));
		y = t->y + (k * (y1 - t->y));
		k += 0.001;
	}
	if (y == 0 || (y == 6 && (x == 11 || x == 7)))
		*color = 0x26B19A;
	else if (x == 0 || (y == 9 && x == 10))
		*color = 0xB777FA;
	else if (y == 14 || (y == 9 && x == 4))
		*color = 0xFADD9B;
	else if (x == 14 || (y >= 2 && y <= 12 && x == 2))
		*color = 0x8F1A3F;
	else
		*color = 0xD70078;
	return (k);
}

void		compute_walls(t_image *t)
{
	t_coord	p;
	float	i;
	int		color;

	set_background(t);
	p.angle = ((t->a / 180) * M_PI);
	i = 0;
	while (i <= WIDTH)
	{
		p.x1 = BOX_X;
		p.y1 = ((BOX_Y * ((WIDTH / 2) - i)) / WIDTH);
		p.tmp = p.x1;
		p.x1 = (p.tmp * cos(p.angle)) - (p.y1 * sin(p.angle));
		p.y1 = (p.tmp * sin(p.angle)) + (p.y1 * cos(p.angle));
		p.x1 = p.x1 + t->x;
		p.y1 = p.y1 + t->y;
		t->k = raycast(t, p.x1, p.y1, &color);
		pixel_put_to_image(t, i, color);
		++i;
	}
	mlx_put_image_to_window(t->mlx, t->win, t->imgp, 0, 0);
}

void		compute_next(t_image *t, float x, float y)
{
	int		a;
	int		b;

	a = x;
	b = y;
	if (x >= 0 && x <= 14 && y >= 0 && y <= 14 && t->lab[a][b] == 0)
	{
		t->x = x;
		t->y = y;
	}
	compute_walls(t);
	mlx_put_image_to_window(t->mlx, t->win, t->imgp, 0, 0);
}
