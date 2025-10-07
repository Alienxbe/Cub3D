/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:13:05 by marykman          #+#    #+#             */
/*   Updated: 2025/10/07 00:35:45 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sfe_event.h"
#include "events.h"

t_game_keys	sfe_to_game_key(t_sfe_keys key)
{
	static t_sfe_keys	keybind[] = {
		SFE_KEY_A,
		SFE_KEY_D,
		SFE_KEY_W,
		SFE_KEY_S,
		SFE_KEY_LEFT,
		SFE_KEY_RIGHT
	};
	t_game_keys			i;

	i = -1;
	while (++i < GAME_KEY_LEN)
		if (keybind[i] == key)
			return (i);
	return (GAME_KEY_LEN);
}
