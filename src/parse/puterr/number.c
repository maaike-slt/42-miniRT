/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:38:03 by adelille          #+#    #+#             */
/*   Updated: 2025/05/28 22:45:31 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

void	puterr_invalid_number(const char *type, const char *invalid_token)
{
	ft_putstr_fd("'", STDERR_FILENO);
	ft_putstr_fd(Y_B_RED, STDERR_FILENO);
	ft_putstr_fd(invalid_token, STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd("' is not a valid ", STDERR_FILENO);
	ft_putstr_fd(type, STDERR_FILENO);
}

void	puterr_between(ssize_t min, ssize_t max)
{
	ft_putstr_fd(" between ", STDERR_FILENO);
	ft_putstr_fd("\033[1;32m", STDERR_FILENO);
	ft_putnbr_fd(min, STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd(" and ", STDERR_FILENO);
	ft_putstr_fd("\033[1;32m", STDERR_FILENO);
	ft_putnbr_fd(max, STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
}

void	puterr_invalid_int(
	const t_line_arg *la, const char *invalid_token, ssize_t min, ssize_t max)
{
	puterr_line(la->line, la->line_index);
	puterr_invalid_number("integer", invalid_token);
	puterr_between(min, max);
	ft_putstr_fd("\n", STDERR_FILENO);
}
