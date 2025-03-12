/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:48:31 by marykman          #+#    #+#             */
/*   Updated: 2025/03/12 08:11:34 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

typedef struct s_map
{
	int		**map;
	t_point	size;
}	t_map;

typedef struct s_player
{
	t_fpoint	pos;
	float		view_angle;	// rad
}	t_player;


typedef struct s_game
{
	t_bool		*running;
	t_map		map;
	t_player	player;
}	t_game;

void	draw_map(t_map map, t_point pos, t_point tile_size, t_img *img);

void	sfe_draw_line(t_img *img, t_point a, t_point b, t_color color);

#endif
