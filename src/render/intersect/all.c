/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:28:37 by adelille          #+#    #+#             */
/*   Updated: 2025/06/05 21:48:48 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_intersect_hit(t_env *env, t_intersect *hit)
{
	if (env->rd.intersect.type == SPHERE)
		fill_intersect_sphere_hit(env, hit);
	else if (env->rd.intersect.type == PLANE)
		fill_intersect_plane_hit(env, hit);
	else if (env->rd.intersect.type == CYLINDER)
		fill_intersect_cylinder_hit(env, hit);
	else if (env->rd.intersect.type == TRIANGLE)
		fill_intersect_triangle_hit(env, hit);
	else if (env->rd.intersect.type == SQUARE)
		fill_intersect_square_hit(env, hit);
}

bool	intersect_all(t_env *env)
{
	bool	hit;

	hit = false;
	hit |= intersect_sphere(env);
	hit |= intersect_plane(env);
	hit |= intersect_cylinder(env);
	hit |= intersect_triangle(env);
	hit |= intersect_square(env);
	return (hit);
}
