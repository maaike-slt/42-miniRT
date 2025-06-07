/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:19:30 by adelille          #+#    #+#             */
/*   Updated: 2025/06/07 18:25:00 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	progress_color(bool intersected)
{
	if (intersected)
		return ((t_color){
			.r = 0x00,
			.g = 0xff,
			.b = 0x00,
			.a = 0xff
		});
	else
		return ((t_color){
			.r = 0xff,
			.g = 0x80,
			.b = 0xff,
			.a = 0xff
		});
}
