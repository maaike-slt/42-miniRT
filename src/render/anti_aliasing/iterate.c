/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:33:54 by adelille          #+#    #+#             */
/*   Updated: 2025/06/07 18:22:44 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static ssize_t	get_start_x(const t_env *env, ssize_t d)
{
	if (d > (ssize_t)env->win.h - 1)
		return (d - ((ssize_t)env->win.h - 1));
	else
		return (0);
}

static ssize_t	get_end_x(const t_env *env, ssize_t d)
{
	if (d < (ssize_t)env->win.w - 1)
		return (d);
	else
		return ((ssize_t)env->win.w - 1);
}

void	reverse_transversal_anti_aliasing(t_env *env)
{
	ssize_t	d;
	ssize_t	end_x;
	ssize_t	x;
	ssize_t	y;
	size_t	index;

	d = env->win.w + env->win.h - 2;
	while (d >= 0)
	{
		end_x = get_end_x(env, d);
		x = get_start_x(env, d);
		while (x <= end_x)
		{
			y = d - x;
			index = (size_t)y * env->win.w + (size_t)x;
			apply_pixel_anti_aliasing(env, (size_t)x, (size_t)y, index);
			if (x > 0)
				set_pixel(env->rd.pov, progress_color(false), index - 1);
			x++;
		}
		putpov(env);
		d--;
	}
}
