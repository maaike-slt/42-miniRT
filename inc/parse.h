/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:53:58 by adelille          #+#    #+#             */
/*   Updated: 2025/05/24 15:04:05 by adelille         ###   ########.fr       */
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

bool	parse_camera(t_env *env, const t_line_arg *la);

#endif
