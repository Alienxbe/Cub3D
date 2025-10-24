/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:32:14 by marykman          #+#    #+#             */
/*   Updated: 2025/10/24 18:23:59 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "sc_main.h"

# define SHADING	true

int		textures_init(t_sc_main *sc);
void	draw_walls(t_img *img, t_ray *ray, t_texture *texture);

#endif
