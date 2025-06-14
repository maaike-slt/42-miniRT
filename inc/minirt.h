/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:30:54 by adelille          #+#    #+#             */
/*   Updated: 2025/06/07 22:08:45 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WITH_OPEN

# include <math.h>
# include <errno.h>
# include <string.h>
# include <stdint.h>

# include "../libft/inc/libft.h"
# include "../mlx/mlx.h"

# include "object.h"

# ifndef WINDOW_NAME
#  define WINDOW_NAME		"miniRT"
# endif

# ifndef ANTI_ALIASING
#  define ANTI_ALIASING		1
# endif

# ifndef SAVE_BMP
#  define SAVE_BMP			1
# endif

# define OUTPUT_PATH		"./output/"
# define BMP_HEADER_SIZE	122

# define MAX_RESOLUTION		65535
# define FLOAT_PRECISION	0.01f

# define DEFAULT_SHININESS	32.0f

typedef struct s_img
{
	void		*ptr;
	t_color_bit	*buf;
	int			bpp;
	int			size_line;
	int			endian;
}	t_img;

typedef struct s_scene
{
	t_camera		*c;
	size_t			c_amt;
	t_ambient		a;
	t_light			*l;
	size_t			l_amt;
	t_triangle		*tr;
	size_t			tr_amt;
	t_square		*sq;
	size_t			sq_amt;
	t_plane			*pl;
	size_t			pl_amt;
	t_sphere		*sp;
	size_t			sp_amt;
	t_cylinder		*cy;
	size_t			cy_amt;
}	t_scene;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

typedef struct s_pov_matrix
{
	t_vec3	right;
	t_vec3	up;
	t_vec3	forward;
}	t_pov_matrix;

typedef struct s_triangle_intersect
{
	t_vec3	edge_ab;
	t_vec3	edge_ac;
	t_vec3	cross_p;
	t_vec3	cross_q;
	float	determinant;
	t_vec3	t_vec;
	float	u;
	float	v;
}	t_triangle_intersect;

typedef struct s_intersect
{
	float			t;
	enum e_object	type;
	void			*object;
	t_vec3			pos;
	t_vec3			normal;
	t_color			color;
}	t_intersect;

typedef struct s_render_data
{
	t_color			ambient_color;
	float			aspect_ratio;
	t_camera		*c;
	t_img			*pov;
	float			viewport_w;
	float			viewport_h;
	t_pov_matrix	pov_matrix;
	t_ray			ray;
	t_intersect		intersect;
	t_vec3			view_direction;
	t_img			original_pov;
}	t_render_data;

typedef struct s_win
{
	void	*ptr;
	size_t	w;
	size_t	h;
}	t_win;

typedef struct s_env
{
	const char		*file;
	void			*mlx;
	t_win			win;
	t_scene			scene;
	t_img			*pov;
	size_t			pov_index;
	t_render_data	rd;
}	t_env;

enum	e_event
{
	KEY_PRESS = 2,
	ON_DESTROY = 17
};

enum	e_mask
{
	NO_EVENT = 0L
};

enum	e_keypress_linux
{
	K_ENTER = 65293,
	K_ESC = 65307,
	K_Z = 122,
	K_Q = 113,
	K_LEFT = 65361,
	K_UP = 65362,
	K_RIGHT = 65363,
	K_DOWN = 65364,
	K_W = 119,
	K_A = 97,
	K_S = 115,
	K_D = 100,
	K_SPACE = 32,
};

bool			init(t_env *env);
bool			init_object(t_env *env);
bool			init_pov(t_env *env);

bool			parse(t_env *env, const char *file);

int				close_win(t_env *env);
bool			create_window(t_env *env);
void			putpov(t_env *env);
void			set_hook(t_env *env);
int				handle_keycode(int keycode, t_env *env);
void			next_camera(t_env *env);
void			prev_camera(t_env *env);

void			render(t_env *env);

void			init_render(t_env *env);
void			init_render_pov(t_env *env);
void			init_render_pixel(t_env *env, size_t x, size_t y);

float			cr(t_color_bit c);
t_color_bit		crr(float c);

t_color			get_pixel(const t_img *img, size_t index);
void			set_pixel(t_img *img, t_color color, size_t index);

t_vec3			vec3_negate(t_vec3 v);
t_vec3			vec3_add(t_vec3 a, t_vec3 b);
t_vec3			vec3_sub(t_vec3 a, t_vec3 b);
t_vec3			vec3_scale(t_vec3 v, float scale);
float			vec3_dot(t_vec3 a, t_vec3 b);
t_vec3			vec3_cross(t_vec3 a, t_vec3 b);
float			vec3_magnitude(t_vec3 v);
t_vec3			vec3_normalize(t_vec3 v);
t_vec3			vec3_reflect(t_vec3 incident, t_vec3 normal);

t_pov_matrix	pov_matrix(const t_camera *c);
t_vec3			calc_ray_direction(t_env *env, size_t x, size_t y);

t_color			get_ambient_color(const t_env *env);

t_color			compute_lighting(t_env *env, t_intersect *hit);
t_vec3			apply_ambient_light(t_color color, t_ambient ambient);
float			compute_specular(
					t_env *env, const t_intersect *hit, const t_light *l);

bool			intersect_all(t_env *env);
bool			intersect_sphere(t_env *env);
bool			intersect_plane(t_env *env);
bool			intersect_cylinder(t_env *env);
float			intersect_cylinder_cap_bottom(t_env *env, const t_cylinder *cy);
float			intersect_cylinder_cap_top(t_env *env, const t_cylinder *cy);
bool			intersect_square(t_env *env);
bool			intersect_triangle(t_env *env);

void			fill_intersect_hit(t_env *env, t_intersect *hit);
void			fill_intersect_sphere_hit(t_env *env, t_intersect *hit);
void			fill_intersect_plane_hit(t_env *env, t_intersect *hit);
void			fill_intersect_cylinder_hit(t_env *env, t_intersect *hit);
void			fill_intersect_square_hit(t_env *env, t_intersect *hit);
void			fill_intersect_triangle_hit(t_env *env, t_intersect *hit);

float			solve_plane_intersection(t_env *env, t_vec3 pos, t_vec3 normal);

bool			keep_closest(t_env *env, float t);

void			apply_anti_aliasing(t_env *env);
void			reverse_transversal_anti_aliasing(t_env *env);
void			apply_pixel_anti_aliasing(
					t_env *env, size_t x, size_t y, size_t index);

t_color			progress_color(bool intersected);

void			save_pov(const t_env *env);
void			write_bmp_header(const t_env *env, int fd, uint32_t pixel_size);

int				free_env(t_env *env);

void			puterr(void);
void			puterr_argc(void);
void			puterr_filetype(void);

#endif
