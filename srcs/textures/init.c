/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:31:44 by marykman          #+#    #+#             */
/*   Updated: 2025/10/24 17:46:11 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "sfe_image.h"
#include "textures.h"

int	textures_init(t_sc_main *sc)
{
	size_t		dir;
	t_texture	*text;

	dir = -1;
	while (++dir < CARDINAL_MAX)
	{
		text = sc->game->textures + dir;
		text->img = sfe_xpm_file_to_image(sc->sfe->mlx_ptr,
				sc->game->map.wall_text_path[dir]);
		if (!text->img.img)
		{
			ft_printf("Error on opening textures\n");
			return (false);
		}
		text->ratio = text->img.size.x / CELL_SIZE;
	}
	return (true);
}
