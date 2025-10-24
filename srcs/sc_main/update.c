/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:34:25 by marykman          #+#    #+#             */
/*   Updated: 2025/10/24 18:12:55 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "minimap.h"
#include "player.h"
#include "raycast.h"
#include "sc_main.h"

void	main_update(t_sc_main *sc)
{
	player_update(sc->game);
	raycast_update(sc->game);
	minimap_update(sc->game);
}

int	sc_main_update(t_sc_main *sc)
{
	main_update(sc);
	main_draw(sc);
	if (SHOW_FPS)
		ft_printf("fps: %d\n", sc->sfe->fps);
	return (sc->running);
}
