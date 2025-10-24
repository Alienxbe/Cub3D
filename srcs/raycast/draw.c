/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:54:53 by marykman          #+#    #+#             */
/*   Updated: 2025/10/24 12:10:51 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sfe_pixel.h"
#include "player.h"
#include "raycast.h"

static t_point	world_to_minimap(t_game *game, t_point p)
{
	double	scale;

	scale = (double)game->minimap.cell_size / CELL_SIZE;
	return ((t_point){p.x * scale, p.y * scale});
}

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

static t_color	shade(t_color col, float shade)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (shade > 1)
		shade = 1;
	r = col >> 16 & 0xFF;
	g = col >> 8 & 0xFF;
	b = col & 0xFF;
	r = (float)r * shade;
	g = (float)g * shade;
	b = (float)b * shade;
	return ((r << 16) | (g << 8) | (b));
}
	// Ici, selon les infos de raycast on peut savoir quelle texture afficher.
	// ray.side == 0 && ray.step_x > 0 : WEST
	// ray.side == 0 && ray.step_x < 0 : EAST
	// ray.side == 1 && ray.step_y > 0 : NORTH
	// ray.side == 1 && ray.step_y < 0 : SOUTH

static void	draw_walls(t_game *game, t_img *img, t_ray *ray)
{
	t_color	col;
	int		wall_height;
	t_point	wall_start;
	t_point	wall_end;

	wall_height = (int)((WIN_HEIGHT / (ray->length * ray->corr_angle)));
	if (wall_height > WIN_HEIGHT)
		wall_height = WIN_HEIGHT;
	wall_start = (t_point){ray - game->rays, (WIN_HEIGHT - wall_height) / 2};
	wall_end = (t_point){ray - game->rays, wall_start.y + wall_height};

	if (ray->side == 0 && ray->step.x > 0)
		col = 0xFF0000;
	else if (ray->side == 0 && ray->step.x < 0)
		col = 0x00FF00;
	else if (ray->side == 1 && ray->step.y > 0)
		col = 0x0000FF;
	else if (ray->side == 1 && ray->step.y < 0)
		col = 0xFFFF00;
	col = shade(col, 5 / ray->length);
	sfe_draw_line(img, wall_start, wall_end, col);
}

void	raycast_draw(t_game *game, t_img *img)
{
	size_t	i;

	i = -1;
	while (++i < WIN_WIDTH)
		draw_walls(game, img, game->rays + i);
}
