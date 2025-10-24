/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:53:49 by marykman          #+#    #+#             */
/*   Updated: 2025/10/24 18:43:38 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"

# define PLAYER_FOV	1.047197551

void	raycast_init(t_game *game);
void	raycast_update(t_game *game);
void	raycast_draw(t_game *game, t_img *img);
void	draw_rays(t_game *game, t_img *img);

void	raycast(t_game *game, t_ray *ray);
void	dda(t_game *game, t_ray *ray);

#endif
