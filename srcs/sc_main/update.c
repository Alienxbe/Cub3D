/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:34:25 by marykman          #+#    #+#             */
/*   Updated: 2025/03/12 08:29:47 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <math.h>
#include "ft_memory.h"
#include "ft_printf.h"
#include "t_sfe.h"
#include "sfe_pixel.h"
#include "sc_main.h"

void	draw_poly(t_img *img, t_point *ps, int pc, t_color color)
{
	for (int i = 0; i < pc; i++)
		sfe_draw_line(img, ps[i], ps[(i + 1) % pc], color);
}

void	draw_player(t_player player, int tile_size, t_img *img)
{
	t_point	player_size = {10, 10};

	sfe_pixel_fill(img, (t_area){{player.pos.x * tile_size - player_size.x / 2, player.pos.y * tile_size - player_size.y / 2}, 
								{player.pos.x * tile_size + player_size.x / 2, player.pos.y * tile_size + player_size.y / 2}}, 0x00C00000);
}

void	draw_view_angle(t_player player, int tile_size, t_img *img)
{
	t_point		start = {player.pos.x * tile_size, player.pos.y * tile_size};
	t_point		finish = {start.x + cos(player.view_angle) * 100, start.y + sin(player.view_angle) * 100};

	ft_printf("finish: %d %d\n", finish.x, finish.y);

	sfe_draw_line(img, start, finish, 0x000000FF);
}

int	sc_main_update(t_sc_main *sc)
{
	// Erase the window;
	// bzero(sc->scene.img->addr, sc->scene.img->size.x * sc->scene.img->size.y * sizeof(t_color));
	draw_map(sc->game->map, (t_point){0}, (t_point){20, 20}, sc->scene.img);
	draw_player(sc->game->player, 20, sc->scene.img);
	draw_view_angle(sc->game->player, 20, sc->scene.img);
	sc->game->player.view_angle -= 0.01;
	ft_printf("fps: %d\n", sc->sfe->fps);
	return (sc->running);
}
