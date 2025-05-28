/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:53:58 by adelille          #+#    #+#             */
/*   Updated: 2025/05/28 22:28:01 by adelille         ###   ########.fr       */
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

bool	parse_vec3(const char *str, t_vec3 *vec3);

bool	parse_camera(t_env *env, const t_line_arg *la);
bool	parse_resolution(t_env *env, const t_line_arg *la);

void	puterr_invalid_type_identifier(
			const char *line,
			size_t line_index,
			const char *identifier);
void	puterr_invalid_token_amount(
			const t_line_arg *la,
			size_t expected,
			const char *line_help);
void	puterr_invalid_int(
			const t_line_arg *la,
			const char *invalid_token,
			ssize_t min,
			ssize_t max);

#endif
