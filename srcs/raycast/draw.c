/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:54:53 by marykman          #+#    #+#             */
/*   Updated: 2025/10/24 16:41:49 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "player.h"
#include "textures.h"
#include "raycast.h"

void	raycast_draw(t_game *game, t_img *img)
{
	size_t		i;
	t_ray		*ray;
	t_texture	*texture;

	i = -1;
	while (++i < WIN_WIDTH)
	{
		ray = &game->rays[i];
		texture = &game->textures[ray->hit_dir];
		ray->wall_height = (WIN_HEIGHT / (ray->length * ray->corr_angle));
		ray->ty_step = (float)texture->img.size.y / (float)ray->wall_height;
		ray->ty_off = 0;
		if (ray->wall_height > WIN_HEIGHT)
		{
			ray->ty_off = (ray->wall_height - WIN_HEIGHT) / 2.0;
			ray->wall_height = WIN_HEIGHT;
		}
		ray->wall_start = (t_point){i, (WIN_HEIGHT - ray->wall_height) / 2};
		draw_walls(img, ray, texture);
	}
}
