/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:19:30 by adelille          #+#    #+#             */
/*   Updated: 2025/06/07 12:06:20 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_render_pixel(t_env *env, size_t x, size_t y)
{
	env->rd.ray.origin = env->rd.c->pos;
	env->rd.ray.direction = calc_ray_direction(env, x, y);
	env->rd.intersect.t = INFINITY;
}

void	init_render_pov(t_env *env)
{
	env->rd.c = &(env->scene.c[env->pov_index]);
	env->rd.pov = &(env->pov[env->pov_index]);
	env->rd.pov_matrix = pov_matrix(env->rd.c);
	env->rd.viewport_h = 2.0f * tanf(env->rd.c->fov * 0.5f * M_PI / 180);
	env->rd.viewport_w = env->rd.viewport_h * env->rd.aspect_ratio;
}

void	init_render(t_env *env)
{
	env->rd.aspect_ratio = (float)env->win.w / (float)env->win.h;
}
