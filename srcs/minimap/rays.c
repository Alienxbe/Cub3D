/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:16:17 by marykman          #+#    #+#             */
/*   Updated: 2025/10/24 16:46:22 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sfe_pixel.h"
#include "minimap.h"

void	draw_rays(t_game *game, t_img *img)
{
	size_t	i;

	i = -1;
	while (++i < WIN_WIDTH)
		sfe_draw_line(img,
			world_to_minimap(game, ft_fpoint_to_point(game->player.pos)),
			world_to_minimap(game, ft_fpoint_to_point(game->rays[i].hit)),
			0x00FF00);
}
