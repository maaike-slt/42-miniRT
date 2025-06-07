/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:24:29 by msloot            #+#    #+#             */
/*   Updated: 2025/06/07 14:28:36 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

/*
Light:
L -40.0,50.0,0.0 0.6 10,0,255
  ∗ identifier: L
  ∗ x, y, z coordinates of the light point: -40.0,50.0,0.0
  ∗ the light brightness ratio in the range [0.0,1.0]: 0.6
  ∗ (bonus) R,G,B colors in the range [0-255]: 10, 0, 255
  ∗ (bonus) shininess in the range [0.0,∞)
  	(must be after the brightness or omitted)
*/

static bool	parse_shininess(const t_line_arg *la, size_t *index, t_light *l)
{
	if (la->split_size == 4)
	{
		l->shininess = DEFAULT_SHININESS;
		return (true);
	}
	l->shininess = ft_atof(la->split[*index]);
	if (l->shininess <= 0)
		return (\
puterr_invalid_float_positive_non_null(la, la->split[*index]), false);
	(*index)++;
	return (true);
}

bool	parse_light(t_env *env, const t_line_arg *la)
{
	t_light	*l;
	size_t	i;

	if (la->split_size != 4 && la->split_size != 5)
		return (puterr_invalid_token_amount(\
la, 4, "<pos in x,y,z> <brightness> <color in r,g,b> [shininess]"), false);
	l = &(env->scene.l[env->scene.l_amt]);
	i = 1;
	if (!parse_vec3(la, la->split[i], &(l->pos)))
		return (false);
	i++;
	l->brightness = ft_atof(la->split[i]);
	if (l->brightness < 0 || l->brightness > 1)
		return (\
puterr_invalid_float(la, la->split[i], 0, 1), false);
	i++;
	if (!parse_shininess(la, &i, l))
		return (false);
	if (!parse_color(la, la->split[i], &(l->color)))
		return (false);
	env->scene.l_amt++;
	return (true);
}
