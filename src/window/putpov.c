/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:51:31 by adelille          #+#    #+#             */
/*   Updated: 2025/06/06 23:53:02 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

inline void	putpov(t_env *env)
{
	mlx_put_image_to_window(
		env->mlx,
		env->win.ptr,
		env->pov[env->pov_index].ptr,
		0, 0);
}
