/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:53:38 by marykman          #+#    #+#             */
/*   Updated: 2025/10/24 16:10:35 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static void	update_steps(t_player *player)
{
	player->step.x = cos(player->view_angle);
	player->step.y = sin(player->view_angle);
}

static void	update_rotation(t_player *player, float speed)
{
	player->view_angle += speed;
	player->view_angle = normalise_angle(player->view_angle);
	update_steps(player);
}

static void	player_update_speed(t_game *game)
{
	if (game->active_keys[GAME_KEY_FORWARD])
	{
		game->player.spd.x += game->player.step.x;
		game->player.spd.y += game->player.step.y;
	}
	if (game->active_keys[GAME_KEY_BACKWARD])
	{
		game->player.spd.x += -game->player.step.x;
		game->player.spd.y += -game->player.step.y;
	}
	if (game->active_keys[GAME_KEY_LEFT])
	{
		game->player.spd.x += game->player.step.y;
		game->player.spd.y += -game->player.step.x;
	}
	if (game->active_keys[GAME_KEY_RIGHT])
	{
		game->player.spd.x += -game->player.step.y;
		game->player.spd.y += game->player.step.x;
	}
	game->player.spd.x *= PLAYER_SPEED;
	game->player.spd.y *= PLAYER_SPEED;
}

void	player_update(t_game *game)
{
	game->player.spd = (t_fpoint){0};
	if (game->active_keys[GAME_KEY_VIEW_LEFT])
		update_rotation(&game->player, -PLAYER_ROTATION_SPEED);
	if (game->active_keys[GAME_KEY_VIEW_RIGHT])
		update_rotation(&game->player, PLAYER_ROTATION_SPEED);
	player_update_speed(game);
	player_move(game);
}
