/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:12:32 by adelille          #+#    #+#             */
/*   Updated: 2025/06/01 16:20:44 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

static void	extract_identifier(const char *line, char *identifier)
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

static bool	count_one_letter_object(
	t_env *env,
	const char *line,
	size_t line_index,
	char identifier)
{
	char	tmp[2];

	if (identifier == 'R' || identifier == 'A')
		return (true);
	else if (identifier == 'C' || identifier == 'c')
		env->scene.c_amt++;
	else if (identifier == 'L' || identifier == 'l')
		env->scene.l_amt++;
	else
	{
		tmp[0] = identifier;
		tmp[1] = '\0';
		puterr_invalid_type_identifier(line, line_index, tmp);
		return (false);
	}
	return (true);
}

static bool	count_two_letter_object(
	t_env *env,
	const char *line,
	size_t line_index,
	const char *identifier)
{
	if (ft_strncmp(identifier, "tr", 2) == 0)
		env->scene.tr_amt++;
	else if (ft_strncmp(identifier, "pl", 2) == 0)
		env->scene.pl_amt++;
	else if (ft_strncmp(identifier, "sp", 2) == 0)
		env->scene.sp_amt++;
	else if (ft_strncmp(identifier, "cy", 2) == 0)
		env->scene.cy_amt++;
	else if (ft_strncmp(identifier, "sq", 2) == 0)
		;
	else
	{
		puterr_invalid_type_identifier(line, line_index, identifier);
		return (false);
	}
	return (true);
}

bool	count_object(t_env *env, const char *line, size_t line_index)
{
	char	identifier[3];

	extract_identifier(line, identifier);
	if (identifier[0] == '\0')
		return (true);
	else if (identifier[1] == '\0')
		return (count_one_letter_object(env, line, line_index, identifier[0]));
	else if (identifier[2] == '\0')
		return (count_two_letter_object(env, line, line_index, identifier));
	else
	{
		puterr_invalid_type_identifier(line, line_index, identifier);
		return (false);
	}
}
