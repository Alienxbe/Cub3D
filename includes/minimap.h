/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:00:06 by marykman          #+#    #+#             */
/*   Updated: 2025/10/07 01:13:01 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3d.h"

void	minimap_init(t_game *game);
void	minimap_update(t_game *game);
void	minimap_draw(t_game *game, t_img *img);

#endif
