/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:00:06 by marykman          #+#    #+#             */
/*   Updated: 2025/10/24 15:17:21 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3d.h"

# define MINIMAP_DEFAULT_SHOW		true

# define MINIMAP_TILE_FLOOR_COLOR	0xAAAAAA
# define MINIMAP_TILE_WALL_COLOR	0x212121

void	minimap_init(t_game *game);
void	minimap_update(t_game *game);
void	minimap_draw(t_game *game, t_img *img);

t_point	world_to_minimap(t_game *game, t_point p);

#endif
