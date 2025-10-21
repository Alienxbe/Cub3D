/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproust <cproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:53:49 by marykman          #+#    #+#             */
/*   Updated: 2025/10/21 18:39:21 by cproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "cub3d.h"

# define PLAYER_ROTATION_SPEED	0.05
# define PLAYER_SPEED			3

void	player_init(t_game *game);
void	player_update(t_game *game);
void	player_draw(t_game *game, t_img *img);
t_ray	raycast(t_game *game, t_fpoint dir, t_point player_pos);

#endif
