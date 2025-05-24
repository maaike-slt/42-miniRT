/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:06:57 by adelille          #+#    #+#             */
/*   Updated: 2025/05/24 16:40:58 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

void	puterr_invalid_type_identifier(
	const char *line, size_t line_index, const char *identifier)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		((char *)line)[len - 1] = '\0';
	puterr();
	ft_putstr_fd(Y_B_RED, STDERR_FILENO);
	ft_putstr_fd("|", STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd(" could not parse line '", STDERR_FILENO);
	ft_putstr_fd("\033[33m", STDERR_FILENO);
	ft_putstr_fd(line, STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd("' at index ", STDERR_FILENO);
	ft_putstr_fd("\033[33m", STDERR_FILENO);
	ft_putunbr_fd(line_index, STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd(":\n", STDERR_FILENO);
	ft_putstr_fd(Y_B_RED, STDERR_FILENO);
	ft_putstr_fd("|", STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd(" '", STDERR_FILENO);
	ft_putstr_fd(identifier, STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd("' is not a valid type identifier\n", STDERR_FILENO);
}
