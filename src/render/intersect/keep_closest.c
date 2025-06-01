/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_closest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:10:44 by adelille          #+#    #+#             */
/*   Updated: 2025/06/01 16:10:46 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

inline bool	keep_closest(t_env *env, float t)
{
	if (t < env->rd.intersect.t)
	{
		env->rd.intersect.t = t;
		return (true);
	}
	return (false);
}
