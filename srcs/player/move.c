/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 02:42:03 by marykman          #+#    #+#             */
/*   Updated: 2025/10/22 17:47:10 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "player.h"

static void	player_move_x(t_game *game, float x)
{
	if (!player_is_solid(game, (t_fpoint){x, 0}))
		game->player.pos.x += x;
	else
		game->player.spd.x = 0;
}

static void	player_move_y(t_game *game, float y)
{
	if (!player_is_solid(game, (t_fpoint){0, y}))
		game->player.pos.y += y;
	else

		game->player.spd.y = 0;
}

void	player_move(t_game *game)
{
	player_move_x(game, game->player.spd.x);
	player_move_y(game, game->player.spd.y);
}
