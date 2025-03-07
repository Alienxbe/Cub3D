/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:32:04 by marykman          #+#    #+#             */
/*   Updated: 2025/03/08 00:40:47 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "sfe.h"
#include "sfe_pixel.h"
#include "sc_main.h"
#include "cub3d.h"

int	main(void)
{
	t_sfe		*sfe;
	t_game		game;
	t_sc_main	sc;

	game = (t_game){0};
	sc = (t_sc_main){0};
	sfe = sfe_init("Cub3D", (t_point){750, 500});

	sc.scene = sfe_new_scene(sfe, &sc);
	sc.scene.f_init = &sc_main_init;
	sc.scene.f_update = &sc_main_update;
	sc.scene.f_destroy = &sc_main_destroy;
	sc.sfe = sfe;

	sc.game = &game;

	sfe_set_active_scene(sfe, &sc.scene);
	sfe_loop(sfe);
	return (EXIT_SUCCESS);
}