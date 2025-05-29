/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:16:21 by msloot            #+#    #+#             */
/*   Updated: 2025/05/24 18:42:33 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	create_window(t_env *env)
{
	env->win.ptr = mlx_new_window(
			env->mlx, env->win.w, env->win.h, WINDOW_NAME);
	if (!env->win.ptr)
		return (false);
	return (true);
}
