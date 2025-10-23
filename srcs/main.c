/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:32:04 by marykman          #+#    #+#             */
/*   Updated: 2025/10/23 12:43:37 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "sfe.h"
#include "sfe_pixel.h"
#include "sc_main.h"
#include "parsing.h"
#include "events.h"
#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_sfe		*sfe;
	t_game		game;
	t_sc_main	sc;
	
	(void)argc; // Unused parameter
	game = (t_game){0};
	sc = (t_sc_main){0};
	game.map = init_map(argv[1]);
	
	sfe = sfe_init(WIN_NAME, (t_point){WIN_WIDTH, WIN_HEIGHT});
	sfe_set_max_fps(sfe, TARGET_FPS);

	sc.scene = sfe_new_scene(sfe, &sc);
	sc.scene.f_init = &sc_main_init;
	sc.scene.f_update = &sc_main_update;
	sc.scene.f_destroy = &sc_main_destroy;
	sc.sfe = sfe;

	sc.game = &game;

	sfe_set_active_scene(sfe, &sc.scene);
	events_init(sfe, &sc);
	sfe_loop(sfe);
	return (EXIT_SUCCESS);
}