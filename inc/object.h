/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:56:12 by msloot            #+#    #+#             */
/*   Updated: 2025/05/29 21:09:43 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_color
{
	char	r;
	char	g;
	char	b;
	char	a;
}	t_color;

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	rot;
	float	fov;
}	t_camera;

typedef struct s_sphere
{
	t_vec3	pos;
	float	d;
	t_color	color;
}	t_sphere;

#endif
