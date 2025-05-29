/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:34:10 by adelille          #+#    #+#             */
/*   Updated: 2025/05/28 22:34:13 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

void	puterr_invalid_type_identifier(
	const char *line, size_t line_index, const char *identifier)
{
	puterr_line(line, line_index);
	ft_putstr_fd("'", STDERR_FILENO);
	ft_putstr_fd(identifier, STDERR_FILENO);
	ft_putstr_fd(Y_RESET, STDERR_FILENO);
	ft_putstr_fd("' is not a valid type identifier\n", STDERR_FILENO);
}
