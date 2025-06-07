/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keycode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:00:10 by msloot            #+#    #+#             */
/*   Updated: 2025/06/07 00:05:58 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	closing_key(int keycode, t_env *env)
{
	if (keycode == K_Q || keycode == K_ESC)
		return (close_win(env), true);
	return (false);
}

static bool	camera_key(int keycode, t_env *env)
{
	if (keycode == K_A || keycode == K_LEFT)
	{
		prev_camera(env);
		return (true);
	}
	else if (keycode == K_D || keycode == K_RIGHT
		|| keycode == K_SPACE || keycode == K_ENTER)
	{
		next_camera(env);
		return (true);
	}
	return (false);
}

int	handle_keycode(int keycode, t_env *env)
{
	if (closing_key(keycode, env))
		return (0);
	else if (camera_key(keycode, env))
		return (0);
	else
	{
		ft_putstr("the keycode ");
		ft_putstr(Y_B_MAG);
		ft_putnbr(keycode);
		ft_putstr(Y_RESET);
		ft_putstr(" does not have any effect\n");
	}
	return (0);
}
