/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:34:25 by marykman          #+#    #+#             */
/*   Updated: 2025/03/08 21:15:11 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_printf.h"
#include "sfe_pixel.h"
#include "t_sfe.h"
#include "sc_main.h"

void	draw_line(t_img *img, t_point a, t_point b, t_color color)
{
	t_point	d;
	int		y;
	int		p;
	int		i;

	if (!img)
		return ;
	d = (t_point){b.x - a.x, b.y - a.y};
	if (!d.x)
		return ;
	y = a.y;
	p = 2 * d.y - d.x;
	i = -1;
	while (++i < b.x + 1)
	{
		sfe_pixel_put(img, (t_point){a.x + i, y}, color);
		if (p >= 0)
		{
			y += 1;
			p = p - 2 * d.x;
		}
		p = p + 2 * d.y;
	}
}

int	sc_main_update(t_sc_main *sc)
{
	ft_bzero(sc->scene.img->addr, sc->scene.img->size.x * sc->scene.img->size.y * sizeof(t_color));

	if (sc->game->a.y >= 500)
		sc->game->direction = -1;
	else if (sc->game->a.y <= 0)
		sc->game->direction = 1;
	
	sc->game->a.y += sc->game->direction * 4;
	
	draw_line(sc->scene.img, (t_point){0, 500 - sc->game->a.y}, sc->game->a, 0x00FFFFFF);

	ft_printf("fps: %d\n", sc->sfe->fps);
	return (sc->running);
}
