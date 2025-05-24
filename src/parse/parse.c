/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:09:57 by msloot            #+#    #+#             */
/*   Updated: 2025/05/24 11:20:11 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	parse_fd(t_env *env, int fd)
{
	char	*line;

	(void)env;
	line = get_next_line(fd);
	while (line)
	{
		ft_putstr(line);
		free(line);
		line = get_next_line(fd);
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
