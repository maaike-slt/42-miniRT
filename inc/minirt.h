/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:30:54 by adelille          #+#    #+#             */
/*   Updated: 2025/05/29 18:33:36 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WITH_OPEN

# include <math.h>
# include <errno.h>
# include <string.h>

# include "../libft/inc/libft.h"
# include "../mlx/mlx.h"

# include "object.h"

# ifndef WINDOW_NAME
#  define WINDOW_NAME	"miniRT"
# endif

# define MAX_RESOLUTION	65535

typedef struct s_img
{
	void	*ptr;
	char	*buf;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_scene
{
	t_camera		*c;
	size_t			c_amt;
	// t_ambient_light	*a;
	size_t			a_amt;
	// t_light			*l;
	size_t			l_amt;
	// t_triangle		*tr;
	size_t			tr_amt;
	// t_plane			*pl;
	size_t			pl_amt;
	t_sphere			*sp;
	size_t			sp_amt;
	// t_cylinder		*cy;
	size_t			cy_amt;
}	t_scene;

typedef struct s_win
{
	void	*ptr;
	size_t	w;
	size_t	h;
}	t_win;

typedef struct s_env
{
	void	*mlx;
	t_win	win;
	t_scene	scene;
	t_img	*pov;
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
};

bool	init(t_env *env);
bool	init_objects(t_env *env);
bool	init_pov(t_env *env);

bool	parse(t_env *env, const char *file);

t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
float	vec3_dot(t_vec3 a, t_vec3 b);
float	vec3_magnitude(t_vec3 v);
t_vec3	vec3_normalize(t_vec3 v);

int		close_win(t_env *env);
bool	create_window(t_env *env);
void	set_hook(t_env *env);
int		handle_keycode(int keycode, t_env *env);

bool	render(t_env *env);
void	init_render(t_env *env);
void	set_pixel(t_img *img, t_color color, size_t index);

int		free_env(t_env *env);

void	puterr(void);
void	puterr_argc(void);

#endif
