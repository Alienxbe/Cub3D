/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproust <cproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 00:46:41 by marykman          #+#    #+#             */
/*   Updated: 2025/10/23 10:54:32 by cproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_scene.h"
#include "minimap.h"
#include "player.h"
#include "sc_main.h"
#include "raycast.h"

void	main_draw(t_sc_main *sc)
{
	// ft_bzero(sc->scene.img->addr, sc->scene.img->size.x * sc->scene.img->size.y * sizeof(t_color));
	// sfe_scene_setbg(sc->scene, 0x60AFAF);
	minimap_draw(sc->game, sc->scene.img);
	//player_draw(sc->game, sc->scene.img);
	raycast_draw(sc->game, sc->scene.img);
}
