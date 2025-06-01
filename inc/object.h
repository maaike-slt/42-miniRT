/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:56:12 by msloot            #+#    #+#             */
/*   Updated: 2025/06/01 17:20:35 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

enum e_object
{
	SPHERE,
	PLANE,
	CYLINDER,
	TRIANGLE,
};

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

typedef u_int8_t	t_color_bit;

typedef struct s_color
{
	t_color_bit	r;
	t_color_bit	g;
	t_color_bit	b;
	t_color_bit	a;
}	t_color;

typedef struct s_light
{
	t_vec3	pos;
	float	brightness;
	t_color	color;
}	t_light;

typedef struct s_ambient
{
	float	lighting_ratio;
	t_color	color;
}	t_ambient;

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	rot;
	float	fov;
}	t_camera;

typedef struct s_sphere
{
	t_vec3	pos;
	float	rad_sq;
	t_color	color;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	pos;
	t_vec3	normal;
	t_color	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	pos;
	t_vec3	normal;
	float	diameter;
	float	height;
	t_color	color;
}	t_cylinder;

#endif
