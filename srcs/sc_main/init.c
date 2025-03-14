/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:29:10 by marykman          #+#    #+#             */
/*   Updated: 2025/03/12 08:18:53 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_pixel.h"
#include "sc_main.h"

int	sc_main_init(t_sc_main *sc)
{
	sc->running = true;
	sc->game->running = &sc->running;
	sc->game->player.pos = (t_fpoint){6, 6.5};
	sc->game->player.view_angle = 0;
	return (true);
}
