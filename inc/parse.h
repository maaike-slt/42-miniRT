/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:53:58 by adelille          #+#    #+#             */
/*   Updated: 2025/05/24 17:46:49 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef struct s_line_arg
{
	char		*line;
	size_t		line_index;
	char		**split;
	size_t		split_size;
}	t_line_arg;

bool	preparse_objects(t_env *env, int fd);
bool	parse_objects(t_env *env, int fd);

bool	parse_camera(t_env *env, const t_line_arg *la);
bool	parse_resolution(t_env *env, const t_line_arg *la);

void	puterr_invalid_type_identifier(
	const char *line, size_t line_index, const char *identifier);
void	puterr_invalid_token_amount(
	const t_line_arg *la, const char *identifier,
	size_t expected, const char *line_help);
void	puterr_invalid_int(
	const t_line_arg *la, const char *invalid_token, ssize_t min, ssize_t max);

#endif
