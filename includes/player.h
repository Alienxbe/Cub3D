/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:53:49 by marykman          #+#    #+#             */
/*   Updated: 2025/10/23 11:51:08 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "ft_bool.h"
# include "cub3d.h"

# define PLAYER_ROTATION_SPEED		0.05
# define PLAYER_SPEED				3
# define PLAYER_MINIMAP_COLOR		0xFF0000
# define PLAYER_MINIMAP_RAY_COLOR	0x00FF00

void	player_init(t_game *game);
void	player_update(t_game *game);
void	player_draw(t_game *game, t_img *img);

void	player_move(t_game *game);
t_bool	player_is_solid(t_game *game, t_fpoint pos);
t_bool	is_hitbox_colliding(t_map *map, t_area hitbox, t_fpoint pos);

#endif
