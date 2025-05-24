/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:06:57 by adelille          #+#    #+#             */
/*   Updated: 2025/05/24 17:51:28 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

static void puterr_line(const char *line, size_t line_index)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		((char *)line)[len - 1] = '\0';
	puterr();
	ft_putstr_fd(Y_B_RED, STDERR_FILENO);
	ft_putstr_fd("| ", STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd("could not parse line '", STDERR_FILENO);
	ft_putstr_fd("\033[33m", STDERR_FILENO);
	ft_putstr_fd(line, STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd("' at index ", STDERR_FILENO);
	ft_putstr_fd("\033[33m", STDERR_FILENO);
	ft_putunbr_fd(line_index, STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd(":\n", STDERR_FILENO);
	ft_putstr_fd(Y_B_RED, STDERR_FILENO);
	ft_putstr_fd("| ", STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
}

void	puterr_invalid_type_identifier(
	const char *line, size_t line_index, const char *identifier)
{
	puterr_line(line, line_index);
	ft_putstr_fd("'", STDERR_FILENO);
	ft_putstr_fd(identifier, STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd("' is not a valid type identifier\n", STDERR_FILENO);
}

void	puterr_invalid_token_amount(
	const t_line_arg *la, const char *identifier, size_t expected, const char *line_help)
{
	puterr_line(la->line, la->line_index);
	ft_putstr_fd(identifier, STDERR_FILENO);
	ft_putstr_fd(" must have ", STDERR_FILENO);
	ft_putstr_fd("\033[1;32m", STDERR_FILENO);
	ft_putunbr_fd(expected, STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd(" tokens, but got ", STDERR_FILENO);
	ft_putstr_fd(Y_B_RED, STDERR_FILENO);
	ft_putunbr_fd(la->split_size, STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	ft_putstr_fd("\033[36m", STDERR_FILENO);
	ft_putstr_fd("help:\t", STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd(line_help, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	puterr_invalid_int(
	const t_line_arg *la, const char *invalid_token, ssize_t min, ssize_t max)
{
	puterr_line(la->line, la->line_index);
	ft_putstr_fd("'", STDERR_FILENO);
	ft_putstr_fd(Y_B_RED, STDERR_FILENO);
	ft_putstr_fd(invalid_token, STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd("' is not a valid integer between ", STDERR_FILENO);
	ft_putstr_fd("\033[1;32m", STDERR_FILENO);
	ft_putnbr_fd(min, STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd(" and ", STDERR_FILENO);
	ft_putstr_fd("\033[1;32m", STDERR_FILENO);
	ft_putnbr_fd(max, STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
