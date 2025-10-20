/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 00:59:58 by marykman          #+#    #+#             */
/*   Updated: 2025/10/20 15:49:54 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void	minimap_init(t_game *game)
{
	game->minimap.show = MINIMAP_DEFAULT_SHOW;
	game->minimap.cell_size = 30;
}