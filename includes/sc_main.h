/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:02:25 by marykman          #+#    #+#             */
/*   Updated: 2025/10/07 00:46:26 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SC_MAIN_H
# define SC_MAIN_H

# include "sfe.h"
# include "cub3d.h"

typedef struct s_sc_main
{
	t_game	*game;

	// SFE part
	t_bool	running;
	t_scene	scene;
	t_sfe	*sfe;
}	t_sc_main;

int		sc_main_init(t_sc_main *sc);
int		sc_main_update(t_sc_main *sc);
int		sc_main_destroy(t_sc_main *sc);

void	main_update(t_sc_main *sc);
void	main_draw(t_sc_main *sc);

void	events_init(t_sfe *sfe, t_sc_main *sc);

#endif
