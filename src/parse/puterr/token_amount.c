/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_amount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:37:29 by adelille          #+#    #+#             */
/*   Updated: 2025/05/29 21:10:33 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

static void	puterr_line_help(
	const char *identifier,
	const char *line_help)
{
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd("\n\033[36mhelp:\t", STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	if (identifier)
	{
		ft_putstr_fd(identifier, STDERR_FILENO);
		ft_putstr_fd(" ", STDERR_FILENO);
	}
	ft_putstr_fd(line_help, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	puterr_invalid_token_amount(
	const t_line_arg *la,
	size_t expected,
	const char *line_help)
{
	puterr_line(la->line, la->line_index);
	ft_putstr_fd(la->split[0], STDERR_FILENO);
	ft_putstr_fd(" must have ", STDERR_FILENO);
	ft_putstr_fd("\033[1;32m", STDERR_FILENO);
	ft_putunbr_fd(expected, STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd(" tokens, but got ", STDERR_FILENO);
	ft_putstr_fd(Y_B_RED, STDERR_FILENO);
	ft_putunbr_fd(la->split_size, STDERR_FILENO);
	puterr_line_help(la->split[0], line_help);
}

void	puterr_invalid_sub_token_amount(
	const t_line_arg *la,
	const char *sub_token,
	t_expected_got eg,
	const char *line_help)
{
	puterr_line(la->line, la->line_index);
	ft_putstr_fd(la->split[0], STDERR_FILENO);
	ft_putstr_fd(" ", STDERR_FILENO);
	ft_putstr_fd(sub_token, STDERR_FILENO);
	ft_putstr_fd(" must have ", STDERR_FILENO);
	ft_putstr_fd("\033[1;32m", STDERR_FILENO);
	ft_putunbr_fd(eg.expected, STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd(" tokens, but got ", STDERR_FILENO);
	ft_putstr_fd(Y_B_RED, STDERR_FILENO);
	ft_putunbr_fd(eg.got, STDERR_FILENO);
	puterr_line_help(NULL, line_help);
}
