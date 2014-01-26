/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 21:16:09 by fmorales          #+#    #+#             */
/*   Updated: 2014/01/22 23:25:07 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIDTH	800
# define HEIGHT	600
# define BOX_X 	1
# define BOX_Y 	1

typedef struct	s_coord
{
	float		angle;
	float		x1;
	float		y1;
	float		tmp;
}				t_coord;

typedef struct	s_image
{
	void		*mlx;
	void		*win;
	void		*imgp;
	int			*img;
	int			bpp;
	int			sizeline;
	int			endian;
	float		x;
	float		y;
	int			x1;
	int			y1;
	float		k;
	float		a;
	int			lab[15][15];
}				t_image;

void			compute_walls(t_image *t);
void			set_background(t_image *t);
float			raycast(t_image *t, float x1, float y1, int *color);
void			pixel_put_to_image(t_image *t, int x, int color);
int				key_hook(int key, t_image *t);
int				expose_hook(t_image *t);
void			compute_next(t_image *t, float x, float y);
void			pixel_put_to_image_down(t_image *t, int y, int h, int color);

#endif /* !__WOLF3D_H__ */
