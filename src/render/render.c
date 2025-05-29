/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:05:51 by msloot            #+#    #+#             */
/*   Updated: 2025/05/29 19:14:14 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	render_pixel(t_env *env, t_img *pov, size_t x, size_t y)
{
	float aspect_ratio = (float)env->win.w / (float)env->win.h;
	float viewport_height = 2.0f;
	float viewport_width = aspect_ratio * viewport_height;
	float u = ((float)x + 0.5f) / env->win.w * viewport_width - viewport_width / 2.0f;
	float v = ((float)y + 0.5f) / env->win.h * viewport_height - viewport_height / 2.0f;
	
	t_vec3	ray_dir = vec3_normalize((t_vec3){u, v, -1.0f});

	float t = intersect_sphere(env->scene.c[0].pos, ray_dir, env->scene.sp[0]);

	if (t > 0)
		set_pixel(pov, env->scene.sp[0].color, y * env->win.w + x);
}

static void	render_pov(t_env *env, t_img *pov)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < env->win.h)
	{
		x = 0;
		while (x < env->win.w)
		{
			render_pixel(env, pov, x, y);
			x++;
		}
		y++;
	}
}

bool	render(t_env *env)
{
	env->scene.sp[0].pos = (t_vec3){0.0f, 0.0f, -3.0f};
	env->scene.sp[0].d = 2.0f;
	env->scene.sp[0].color = (t_color){0xff, 0x00, 0x00, 0xff};
	init_render(env);
	render_pov(env, env->pov + 0);
	return (true);
}
