/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 12:50:42 by fmorales          #+#    #+#             */
/*   Updated: 2014/01/19 22:36:02 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <mlx.h>
#include "wolf3d.h"

static void	copy_map(int lab[15][15], t_image *t)
{
	int		i;
	int		j;

	i = 0;
	while (i < 15)
	{
		j = 0;
		while (j < 15)
		{
			t->lab[i][j] = lab[i][j];
			j++;
		}
		i++;
	}
}

static void	set_map(t_image *t)
{
	int		lab[15][15] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	copy_map(lab, t);
}

int			key_hook(int key, t_image *t)
{
	float	x;
	float	y;

	x = -1;
	y = -1;
	if (key == 65307)
		exit(1);
	if (key == 65362)
	{
		x = t->x + (0.2 * cos((t->a / 180) * M_PI));
		y = t->y + (0.2 * sin((t->a / 180) * M_PI));
	}
	else if (key == 65364)
	{
		x = t->x - (0.2 * cos((t->a / 180) * M_PI));
		y = t->y - (0.2 * sin((t->a / 180) * M_PI));
	}
	if (key == 65363)
		t->a = t->a - 15;
	if (key == 65361)
		t->a = t->a + 15;
	compute_next(t, x, y);
	return (1);
}

int			expose_hook(t_image *t)
{
	mlx_put_image_to_window(t->mlx, t->win, t->imgp, 0, 0);
	return (0);
}

int			main(void)
{
	t_image	t;

	t.mlx = mlx_init();
	t.win = mlx_new_window(t.mlx, WIDTH, HEIGHT, "WOLF3D");
	t.imgp = mlx_new_image(t.mlx, WIDTH, HEIGHT);
	t.img = (int *)mlx_get_data_addr(t.imgp, &t.bpp, &t.sizeline, &t.endian);
	t.x = 12;
	t.y = 1.5;
	t.a = 180;
	set_map(&t);
	compute_walls(&t);
	mlx_expose_hook(t.win, expose_hook, &t);
	mlx_key_hook(t.win, key_hook, &t);
	mlx_hook(t.win, 2, (1L << 0), key_hook, &t);
	mlx_do_key_autorepeaton(t.mlx);
	mlx_loop(t.mlx);
	return (0);
}
