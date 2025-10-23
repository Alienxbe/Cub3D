/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:53:49 by marykman          #+#    #+#             */
/*   Updated: 2025/10/23 11:51:32 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"

t_ray	raycast(t_game *game, t_fpoint player_pos, t_ray ray, int i);
void	raycast_draw(t_game *game, t_img *img);

#endif
