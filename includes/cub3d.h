/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproust <cproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:48:31 by marykman          #+#    #+#             */
/*   Updated: 2025/06/27 17:29:51 by cproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

# include "t_color.h"
# include "ft_point.h"
# include "t_img.h"

/* Enum */

typedef enum e_cardinal_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	CARDINAL_MAX
}	t_cardinal_dir;

typedef enum e_map_tile
{
	TILE_FLOOR = 0,
	TILE_WALL = 1,
	TILE_N = 2,
	TILE_S = 3,
	TILE_E = 4,
	TILE_W = 5,
	TILE_EMPTY = 6,
	TILE_TERM = 7
}	t_map_tile;

/* Structures */

typedef struct s_map
{
	int				**map;
	t_point			size;
	t_point			player_pos;
	t_cardinal_dir	player_dir;
	t_color			ceiling_col;	// t_color est juste un unsigned int (#AA RR GG BB)
	t_color			floor_col;
	char			*wall_text[CARDINAL_MAX];
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
