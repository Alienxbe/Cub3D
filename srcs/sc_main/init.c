/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:29:10 by marykman          #+#    #+#             */
/*   Updated: 2025/03/08 00:44:48 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_pixel.h"
#include "sc_main.h"

void	draw(t_sc_main *sc)
{
	sfe_pixel_fill(sc->scene.img, (t_area){{50, 50}, {100, 100}}, 0x00FF00FF);
}

int	sc_main_init(t_sc_main *sc)
{
	sc->running = true;
	sc->game->running = &sc->running;

	draw(sc);
	return (true);
}
