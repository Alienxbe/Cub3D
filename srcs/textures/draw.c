/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:33:45 by marykman          #+#    #+#             */
/*   Updated: 2025/10/24 18:27:44 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfe_color.h"
#include "sfe_pixel.h"
#include "textures.h"

t_color	shade(t_color col, float shade)
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

static float	get_tx(t_ray *ray, t_texture *texture)
{
	float	tx;

	if (ray->side)
	{
		tx = ((float)((int)(ray->hit.x) % CELL_SIZE)) * texture->ratio;
		if (ray->angle < M_PI)
			tx = texture->img.size.x - tx - 1;
	}
	else
	{
		tx = ((float)((int)(ray->hit.y) % CELL_SIZE)) * texture->ratio;
		if (ray->angle > M_PI / 2 && ray->angle < (float)(3 * M_PI) / 2)
			tx = texture->img.size.x - tx - 1;
	}
	return (tx);
}

void	draw_walls(t_img *img, t_ray *ray, t_texture *texture)
{
	t_color	col;
	int		y;
	float	ty;
	float	tx;

	tx = get_tx(ray, texture);
	ty = ray->ty_off * ray->ty_step;
	y = -1;
	while (y++ < ray->wall_height)
	{
		col = sfe_color_get(&texture->img, (t_point){tx, ty});
		if (SHADING)
			col = shade(col, 3 / ray->length);
		sfe_pixel_put(img,
			(t_point){ray->wall_start.x, ray->wall_start.y + y}, col);
		ty += ray->ty_step;
	}
}
