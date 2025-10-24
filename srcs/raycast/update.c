/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:43:50 by marykman          #+#    #+#             */
/*   Updated: 2025/10/24 16:09:27 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "raycast.h"

static void	update_hit_dir(t_ray *ray)
{
	if (ray->side == 0 && ray->step.x > 0)
		ray->hit_dir = WEST;
	else if (ray->side == 0 && ray->step.x < 0)
		ray->hit_dir = EAST;
	else if (ray->side == 1 && ray->step.y > 0)
		ray->hit_dir = NORTH;
	else if (ray->side == 1 && ray->step.y < 0)
		ray->hit_dir = SOUTH;
}

void	raycast_update(t_game *game)
{
	size_t	i;
	float	angle;

	angle = game->player.view_angle - (PLAYER_FOV / 2);
	i = -1;
	while (++i < WIN_WIDTH)
	{
		game->rays[i].dir = (t_fpoint){cos(angle), sin(angle)};
		game->rays[i].angle = normalise_angle(angle);
		game->rays[i].corr_angle = cos(angle - game->player.view_angle);
		raycast(game, &game->rays[i]);
		update_hit_dir(&game->rays[i]);
		angle += game->ray_angle_step;
	}
}
