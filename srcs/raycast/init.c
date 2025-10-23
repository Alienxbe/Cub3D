/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:47:55 by marykman          #+#    #+#             */
/*   Updated: 2025/10/23 12:50:42 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	raycast_init(t_game *game)
{
	game->ray_angle_step = (PLAYER_FOV / (float)WIN_WIDTH);
}