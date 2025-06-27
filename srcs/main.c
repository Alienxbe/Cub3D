/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproust <cproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:32:04 by marykman          #+#    #+#             */
/*   Updated: 2025/06/27 16:10:33 by cproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "sfe.h"
#include "sfe_pixel.h"
#include "sc_main.h"
#include "cub3d.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_sfe		*sfe;
	t_game		game;
	t_sc_main	sc;
	
	(void)argc; // Unused parameter
	game = (t_game){0};
	sc = (t_sc_main){0};

	// TODO: Parsing
	game.map = init_map(argv[1]);
	
	sfe = sfe_init("Cub3D", (t_point){700, 700});
	sfe_set_max_fps(sfe, 120);

	sc.scene = sfe_new_scene(sfe, &sc);
	sc.scene.f_init = &sc_main_init;
	sc.scene.f_update = &sc_main_update;
	sc.scene.f_destroy = &sc_main_destroy;
	sc.sfe = sfe;

	sc.game = &game;

	game.map.map = (int *[]){
		(int []){1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		(int []){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		(int []){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		(int []){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		(int []){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		(int []){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		(int []){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		(int []){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		(int []){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		(int []){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		(int []){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		(int []){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		(int []){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		(int []){1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};
	game.map.size = (t_point){13, 14};

	sfe_set_active_scene(sfe, &sc.scene);
	sfe_loop(sfe);
	return (EXIT_SUCCESS);
}