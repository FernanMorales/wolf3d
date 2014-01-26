/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fernan.moralesayuso@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 20:58:16 by fmorales          #+#    #+#             */
/*   Updated: 2014/01/19 22:29:24 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_background(t_image *t)
{
	int	i;

	i = 0;
	while (i < (t->sizeline * HEIGHT / 2))
	{
		t->img[i / 4] = 0xA1FFFF - ((i * 2.2) / 10000);
		++i;
	}
	while (i < (t->sizeline * HEIGHT))
	{
		t->img[i / 4] = 0x664F47 + ((i * 0.01) / 10000);
		i++;
	}
}
