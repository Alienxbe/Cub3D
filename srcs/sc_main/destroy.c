/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:38:57 by marykman          #+#    #+#             */
/*   Updated: 2025/10/24 17:40:25 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_image.h"
#include "parsing.h"
#include "sc_main.h"

static void	destroy_textures(t_sc_main *sc)
{
	size_t	i;

	i = -1;
	while (++i < CARDINAL_MAX)
		sfe_image_destroy(sc->sfe->mlx_ptr, &sc->game->textures[i].img);
}

int	sc_main_destroy(t_sc_main *sc)
{
	free_map(sc->game->map);
	destroy_textures(sc);
	return (true);
}
