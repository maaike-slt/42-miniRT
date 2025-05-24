/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:09:57 by msloot            #+#    #+#             */
/*   Updated: 2025/05/24 16:46:29 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

static bool with_file(
	t_env *env, const char *file, bool (*parse_fn)(t_env *, int))
{
	int		fd;
	bool	res;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		puterr();
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		return (false);
	}
	res = parse_fn(env, fd);
	close(fd);
	return (res);
}

static bool validate_scene(t_env *env)
{
	if (env->scene.c_amt == 0)
		return (puterr(), ft_putstr_fd("no camera found\n", STDERR_FILENO), false);
	// if ...
	return (true);
}

bool	parse(t_env *env, const char *file)
{
	// TODO: check if file ends in `.rt`
	if (!with_file(env, file, preparse_objects))
		return (false);
	if (!with_file(env, file, parse_objects))
		return (false);
	if (!validate_scene(env))
		return (false);
	return (true);
}
