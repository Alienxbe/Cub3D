/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:29:10 by marykman          #+#    #+#             */
/*   Updated: 2025/10/24 13:07:47 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_pixel.h"
#include "minimap.h"
#include "player.h"
#include "raycast.h"
#include "textures.h"
#include "sc_main.h"

int	sc_main_init(t_sc_main *sc)
{
	sc->running = true;
	sc->game->running = &sc->running;
	if (!textures_init(sc))
		return (false);
	player_init(sc->game);
	minimap_init(sc->game);
	raycast_init(sc->game);
	return (true);
}
