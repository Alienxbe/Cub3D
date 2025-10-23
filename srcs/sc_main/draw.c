/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 00:46:41 by marykman          #+#    #+#             */
/*   Updated: 2025/10/23 16:37:29 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "sfe_scene.h"
#include "minimap.h"
#include "player.h"
#include "sc_main.h"
#include "raycast.h"
#include "sfe_pixel.h"

void	main_draw(t_sc_main *sc)
{
	sfe_pixel_fill(
		sc->scene.img,
		(t_area){{0, 0}, {WIN_WIDTH, WIN_HEIGHT / 2}},
		sc->game->map.ceiling_col);
	sfe_pixel_fill(
		sc->scene.img,
		(t_area){{0, WIN_HEIGHT / 2}, {WIN_WIDTH, WIN_HEIGHT}},
		sc->game->map.floor_col);
	raycast_draw(sc->game, sc->scene.img);
	minimap_draw(sc->game, sc->scene.img);
}
