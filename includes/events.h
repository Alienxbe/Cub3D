/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:35:33 by marykman          #+#    #+#             */
/*   Updated: 2025/10/07 00:32:54 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "sfe_event.h"

typedef enum e_game_keys
{
	GAME_KEY_LEFT,
	GAME_KEY_RIGHT,
	GAME_KEY_FORWARD,
	GAME_KEY_BACKWARD,
	GAME_KEY_VIEW_LEFT,
	GAME_KEY_VIEW_RIGHT,
	GAME_KEY_LEN
}	t_game_keys;

t_game_keys	sfe_to_game_key(t_sfe_keys key);

#endif
