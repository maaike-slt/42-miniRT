/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_amount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:37:29 by adelille          #+#    #+#             */
/*   Updated: 2025/05/28 22:37:35 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

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
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	ft_putstr_fd("\033[36m", STDERR_FILENO);
	ft_putstr_fd("help:\t", STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd(la->split[0], STDERR_FILENO);
	ft_putstr_fd(" ", STDERR_FILENO);
	ft_putstr_fd(line_help, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
