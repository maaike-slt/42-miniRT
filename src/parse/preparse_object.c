/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparse_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:26:02 by adelille          #+#    #+#             */
/*   Updated: 2025/06/03 20:31:38 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

static void	reset_scene_amt(t_env *env)
{
	env->scene.c_amt = 0;
	env->scene.l_amt = 0;
	env->scene.tr_amt = 0;
	env->scene.sq_amt = 0;
	env->scene.pl_amt = 0;
	env->scene.sp_amt = 0;
	env->scene.cy_amt = 0;
}

bool	preparse_object(t_env *env, int fd)
{
	size_t	i;
	char	*line;
	bool	valid;

	valid = true;
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!count_object(env, line, i))
			valid = false;
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (!valid)
		return (false);
	init_object(env);
	reset_scene_amt(env);
	return (true);
}
