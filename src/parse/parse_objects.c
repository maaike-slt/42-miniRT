/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:11:31 by adelille          #+#    #+#             */
/*   Updated: 2025/05/29 22:38:08 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

static bool	parse_line_arg(t_env *env, const t_line_arg *la)
{
	if (ft_strcmp(la->split[0], "R") == 0)
		return (parse_resolution(env, la));
	if (ft_strcmp(la->split[0], "C") == 0 || ft_strcmp(la->split[0], "c") == 0)
		return (parse_camera(env, la));
	if (ft_strcmp(la->split[0], "sp") == 0)
		return (parse_sphere(env, la));
	// if ...
	return (true);
}

static bool	parse_line(t_env *env, t_line_arg *la)
{
	if (la->line[0] == '\0')
		return (true);
	la->split = ft_split_whitespace(la->line);
	if (!la->split)
		return (false);
	la->split_size = ft_2d_size((const void **)(la->split));
	if (la->split_size <= 1)
		return (true);
	return (parse_line_arg(env, la));
}

bool	parse_objects(t_env *env, int fd)
{
	t_line_arg	la;
	bool		res;

	la.line_index = 0;
	la.line = get_next_line(fd);
	while (la.line)
	{
		res = parse_line(env, &la);
		if (la.split)
			ft_2d_free((void ***)(&la.split), la.split_size);
		free(la.line);
		if (!res)
			return (false);
		la.line = get_next_line(fd);
		la.line_index++;
	}
	return (true);
}
