/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproust <cproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:53:38 by marykman          #+#    #+#             */
/*   Updated: 2025/10/23 11:02:07 by cproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

#include <stdio.h>

static void	update_steps(t_player *player)
{
	player->step.x = cos(player->view_angle);
	player->step.y = sin(player->view_angle);
}

static void	update_rotation(t_player *player, float speed)
{
	player->view_angle += speed;
	if (player->view_angle < 0)
		player->view_angle += 2 * M_PI;
	if (player->view_angle > 2 * M_PI)
		player->view_angle -= 2 * M_PI;
	update_steps(player);
}

void	player_update(t_game *game)
{
	game->player.spd = (t_point){0};
	if (game->active_keys[GAME_KEY_VIEW_LEFT])
		update_rotation(&game->player, PLAYER_ROTATION_SPEED);
	if (game->active_keys[GAME_KEY_VIEW_RIGHT])
		update_rotation(&game->player, -PLAYER_ROTATION_SPEED);
	if (game->active_keys[GAME_KEY_FORWARD])
	{
		game->player.spd.x = game->player.step.x * PLAYER_SPEED;
		game->player.spd.y = game->player.step.y * PLAYER_SPEED;
	}
	if (game->active_keys[GAME_KEY_BACKWARD])
	{
		game->player.spd.x = -game->player.step.x * PLAYER_SPEED;
		game->player.spd.y = -game->player.step.y * PLAYER_SPEED;
	}
	if (game->active_keys[GAME_KEY_LEFT])
	{
		game->player.spd.x = -game->player.step.x * PLAYER_SPEED;
		game->player.spd.y = game->player.step.y * PLAYER_SPEED;
	}
	if (game->active_keys[GAME_KEY_RIGHT])
	{
		game->player.spd.x = game->player.step.x * PLAYER_SPEED;
		game->player.spd.y = -game->player.step.y * PLAYER_SPEED;
	}
	game->player.pos = add_point(game->player.pos, game->player.spd);
}
