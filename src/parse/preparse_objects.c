/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparse_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:26:02 by adelille          #+#    #+#             */
/*   Updated: 2025/05/24 17:49:27 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

static void extract_identifier(const char *line, char *identifier)
{
	size_t	line_i;
	size_t	id_i;

	identifier[0] = '\0';
	identifier[1] = '\0';
	identifier[2] = '\0';
	line_i = 0;
	while (line[line_i] && ft_isspace(line[line_i]))
		line_i++;
	id_i = 0;
	while (line[line_i] && !ft_isspace(line[line_i]) && id_i < 2)
	{
		identifier[id_i] = line[line_i];
		line_i++;
		id_i++;
	}
}

static bool count_object(t_env *env, const char *line, size_t line_index)
{
	char	identifier[3];

	extract_identifier(line, identifier);
	if (identifier[0] == '\0')
		return (true);
	else if (identifier[1] == '\0')
	{
		if (identifier[0] == 'R')
			;
		else if (identifier[0] == 'C' || identifier[0] == 'c')
			env->scene.c_amt++;
		else if (identifier[0] == 'A')
			env->scene.a_amt++;
		else if (identifier[0] == 'L')
			env->scene.l_amt++;
		else
		{
			puterr_invalid_type_identifier(line, line_index, identifier);
			return (false);
		}
	}
	else if (identifier[2] == '\0')
	{
		if (ft_strncmp(identifier, "tr", 2) == 0)
			env->scene.tr_amt++;
		else if (ft_strncmp(identifier, "pl", 2) == 0)
			env->scene.pl_amt++;
		else if (ft_strncmp(identifier, "sp", 2) == 0)
			env->scene.sp_amt++;
		else if (ft_strncmp(identifier, "cy", 2) == 0)
			env->scene.cy_amt++;
		else
		{
			puterr_invalid_type_identifier(line, line_index, identifier);
			return (false);
		}
	}
	return (true);
}

static void reset_scene_amt(t_env *env)
{
	env->scene.c_amt = 0;
//	env->scene.a_amt = 0;
//	env->scene.l_amt = 0;
//	env->scene.tr_amt = 0;
//	env->scene.pl_amt = 0;
//	env->scene.sp_amt = 0;
//	env->scene.cy_amt = 0;
}

bool	preparse_objects(t_env *env, int fd)
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
	init_objects(env);
	reset_scene_amt(env);
	return (true);
}
