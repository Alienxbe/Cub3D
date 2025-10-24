/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:48:31 by marykman          #+#    #+#             */
/*   Updated: 2025/10/24 12:11:03 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

# include "math.h"
# include "t_color.h"
# include "ft_point.h"
# include "ft_area.h"
# include "t_img.h"
# include "events.h"

/* Defines */

# define WIN_NAME	"Cub3D"
# define WIN_WIDTH	1080
# define WIN_HEIGHT	720
# define TARGET_FPS	60

# define CELL_SIZE	32

# ifndef M_PI
#  define M_PI		3.1415
# endif

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
	TILE_FLOOR = 8,
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
	char			*wall_text_path[CARDINAL_MAX];
}	t_map;

typedef struct s_minimap
{
	int		cell_size;
	// BONUS: Center on player
	// BONUS: Allow rotations
	t_bool	show;
}	t_minimap;


typedef struct s_player
{
	t_fpoint	pos;
	t_fpoint	spd;
	t_fpoint	step;
	t_fpoint	step_left;
	t_area		hitbox;
	float		view_angle;	// rad
}	t_player;

typedef struct s_ray
{
	t_fpoint	dir;
	t_fpoint		hit;
	float		angle;
	t_point		map_pos;
	t_fpoint	delta;
	t_fpoint	c_dist;
	int			side;
	t_point		step;
	float		length;
	float		corr_angle;
}	t_ray;

typedef struct s_game
{
	t_bool		*running;
	t_map		map;
	t_player	player;
	t_minimap	minimap;
	t_ray		rays[WIN_WIDTH];
	float		ray_angle_step;
	t_bool		active_keys[GAME_KEY_LEN];
}	t_game;

#endif
