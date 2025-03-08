/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:48:31 by marykman          #+#    #+#             */
/*   Updated: 2025/03/08 21:06:55 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

typedef struct s_game
{
	t_bool	*running;
	t_point	a;
	int		direction;
}	t_game;

#endif
