/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:29:10 by marykman          #+#    #+#             */
/*   Updated: 2025/03/08 21:13:28 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_pixel.h"
#include "sc_main.h"

int	sc_main_init(t_sc_main *sc)
{
	sc->running = true;
	sc->game->running = &sc->running;
	sc->game->a = (t_point){750, 0};
	sc->game->direction = 1;
	return (true);
}
