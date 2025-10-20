/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:34:25 by marykman          #+#    #+#             */
/*   Updated: 2025/10/20 15:25:52 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include "player.h"
#include "sc_main.h"
#include <stdio.h>

void	main_update(t_sc_main *sc)
{
	minimap_update(sc->game);
	player_update(sc->game);
}

int	sc_main_update(t_sc_main *sc)
{
	main_update(sc);
	main_draw(sc);
	// printf("fps: %d\n", sc->sfe->fps);
	return (sc->running);
}
