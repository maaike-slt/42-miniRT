/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:30:54 by adelille          #+#    #+#             */
/*   Updated: 2025/05/21 19:02:33 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WITH_OPEN

# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>

# include "../libft/inc/libft.h"
# include "../mlx/mlx.h"

# ifndef WINDOW_NAME
#  define WINDOW_NAME	"miniRT"
# endif

typedef struct s_img
{
	void	*ptr;
	int		w;
	int		h;
}	t_img;

typedef struct s_win
{
	void	*ptr;
	size_t	w;
	size_t	h;
}	t_win;

typedef struct s_env
{
	void			*mlx;
	t_win			win;
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

int		close_win(t_env *env);
bool	create_window(t_env *env);
void	set_hook(t_env *env);
int		handle_keycode(int keycode, t_env *env);

#endif
