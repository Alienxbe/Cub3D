/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykman <marykman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 04:29:59 by marykman          #+#    #+#             */
/*   Updated: 2025/03/12 04:55:30 by marykman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_math.h"
#include "sfe_image.h"
#include "sfe_pixel.h"

static void	update_vars(int *var_a, int var_step, int *err, int var_delta)
{
	*var_a += var_step;
	*err += var_delta;
}

void	sfe_draw_line(t_img *img, t_point a, t_point b, t_color color)
{
	t_point	delta;
	t_point	step;
	int		err;
	int		err_tmp;

	if (!img)
		return ;
	delta = (t_point){abs(b.x - a.x), -abs(b.y - a.y)};
	step = (t_point){ft_signint(b.x - a.x), ft_signint(b.y - a.y)};
	err = delta.y + delta.x;
	while (1)
	{
		sfe_pixel_put(img, a, color);
		if (a.x == b.x && a.y == b.y)
			return ;
		err_tmp = 2 * err;
		if (err_tmp >= delta.y)
			update_vars(&a.x, step.x, &err, delta.y);
		if (err_tmp <= delta.x)
			update_vars(&a.y, step.y, &err, delta.x);
	}
}
