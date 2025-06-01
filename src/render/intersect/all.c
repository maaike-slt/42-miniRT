/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:28:37 by adelille          #+#    #+#             */
/*   Updated: 2025/06/01 16:16:52 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_intersect_hit(t_env *env, t_intersect *hit)
{
	if (env->rd.intersect.type == SPHERE)
		fill_intersect_sphere_hit(env, hit);
	else if (env->rd.intersect.type == PLANE)
		fill_intersect_plane_hit(env, hit);
//	else if (env->rd.intersect.type == CYLINDER)
//		fill_intersect_cylinder_hit(env, hit);
//	else if (env->rd.intersect.type == TRIANGLE)
//		fill_intersect_triangle_hit(env, hit);
}

bool	intersect_all(t_env *env)
{
	bool	hit;

	hit = false;
	hit |= intersect_sphere(env);
	hit |= intersect_plane(env);
	// hit |= intersect_cylinder(env);
	// hit |= intersect_triangle(env);
	return (hit);
}
