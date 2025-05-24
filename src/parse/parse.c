/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:09:57 by msloot            #+#    #+#             */
/*   Updated: 2025/05/24 15:05:32 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

static void	puterr_invalid_type_identifier(const t_line_arg *la)
{
	size_t	len;

	len = ft_strlen(la->line);
	if (len > 0 && la->line[len - 1] == '\n')
		la->line[len - 1] = '\0';
	ft_puterr("could not parse line '");
	ft_putstr_fd(la->line, STDERR_FILENO);
	ft_putstr_fd("' at index ", STDERR_FILENO);
	ft_putunbr_fd(la->line_index, STDERR_FILENO);
	ft_putstr_fd(" invalid type identifier\n", STDERR_FILENO);
}

static bool	parse_line_arg(t_env *env, const t_line_arg *la)
{
	if (ft_strcmp(la->split[0], "C") == 0)
		return (parse_camera(env, la));
	// else if ...
	else
		return (puterr_invalid_type_identifier(la), /*false*/ true);	// update when all object are parsed
}

static bool parse_line(t_env *env, t_line_arg *la)
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

static bool	parse_fd(t_env *env, int fd)
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

bool	parse(t_env *env, const char *file)
{
	int		fd;
	// check if file ends in `.rt`
	// check if file exist
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_puterr(strerror(errno)), false);
	if (!parse_fd(env, fd))
		return (close(fd), false);
	close(fd);
	// check if scene is valid (right amount of camera, etc ...)
	return (true);
}
