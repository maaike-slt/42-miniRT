/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:09:57 by msloot            #+#    #+#             */
/*   Updated: 2025/05/24 12:06:22 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	puterr_invalid_type_identifier(const char *line, size_t index)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		((char *)(line))[len - 1] = '\0';
	ft_puterr("could not parse line '");
	ft_putstr_fd(line, STDERR_FILENO);
	ft_putstr_fd("' at index ", STDERR_FILENO);
	ft_putunbr_fd(index, STDERR_FILENO);
	ft_putstr_fd(" invalid type identifier\n", STDERR_FILENO);
}

static bool	parse_line(
	t_env *env, char **split, size_t size, const char *line, size_t index)
{
	if (ft_strcmp(split[0], "C") == 0)
		return (parse_camera(env, split, size));
	// else if ...
	else
		return (puterr_invalid_type_identifier(line, index), /*false*/ true);	// update when all object are parsed
}

static bool	parse_fd(t_env *env, int fd)
{
	size_t	i;
	char	*line;
	char	**split;
	size_t	split_size;
	bool	res;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\0')
		{
			i++;
			continue ;
		}
		split = ft_split_whitespace(line);
		if (!split)
			return (false);
		split_size = ft_2d_size((const void **)split);
		if (split_size <= 1)
		{
			i++;
			continue ;
		}
		res = parse_line(env, split, split_size, line, i);
		ft_2d_free((void ***)(&split), split_size);
		free(line);
		if (!res)
			return (false);
		line = get_next_line(fd);
		i++;
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
