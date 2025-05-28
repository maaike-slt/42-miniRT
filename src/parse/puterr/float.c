/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:42:17 by adelille          #+#    #+#             */
/*   Updated: 2025/05/28 22:45:51 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

void	puterr_invalid_float(
	const t_line_arg *la, const char *invalid_token, ssize_t min, ssize_t max)
{
	puterr_line(la->line, la->line_index);
	puterr_invalid_number("float", invalid_token);
	puterr_between(min, max);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	puterr_invalid_float_positive_non_null(
	const t_line_arg *la, const char *invalid_token)
{
	puterr_line(la->line, la->line_index);
	puterr_invalid_number("positive float greater than 0", invalid_token);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	puterr_invalid_float_unbound(
	const t_line_arg *la, const char *invalid_token)
{
	puterr_line(la->line, la->line_index);
	puterr_invalid_number("unbound float", invalid_token);
	ft_putstr_fd("\n", STDERR_FILENO);
}
