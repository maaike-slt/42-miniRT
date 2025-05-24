/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:06:57 by adelille          #+#    #+#             */
/*   Updated: 2025/05/24 15:07:06 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

void	puterr_invalid_type_identifier(const t_line_arg *la)
{
	size_t	len;

	len = ft_strlen(la->line);
	if (len > 0 && la->line[len - 1] == '\n')
		la->line[len - 1] = '\0';
	ft_puterr("could not parse line '");
	ft_putstr_fd(la->line, STDERR_FILENO);
	ft_putstr_fd("' at index ", STDERR_FILENO);
	ft_putunbr_fd(la->line_index, STDERR_FILENO);
	ft_putstr_fd(" invalid type identifier\n", STDERR_FILENO);
}
