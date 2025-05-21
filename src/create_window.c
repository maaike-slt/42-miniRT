/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:16:21 by msloot            #+#    #+#             */
/*   Updated: 2025/05/21 18:53:54 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	create_window(t_env *env)
{
	env->win.w = 400;
	env->win.h = 400;
	env->win.ptr = mlx_new_window(
			env->mlx, env->win.w, env->win.h, WINDOW_NAME);
	if (!env->win.ptr)
		return (false);
	return (true);
}
