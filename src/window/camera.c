/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:48:19 by adelille          #+#    #+#             */
/*   Updated: 2025/06/06 23:58:54 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	next_camera(t_env *env)
{
	env->pov_index = (env->pov_index + 1) % env->scene.c_amt;
	putpov(env);
}

void	prev_camera(t_env *env)
{
	if (env->pov_index == 0)
		env->pov_index = env->scene.c_amt - 1;
	else
		env->pov_index--;
	putpov(env);
}
