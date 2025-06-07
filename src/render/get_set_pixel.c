/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:20:03 by adelille          #+#    #+#             */
/*   Updated: 2025/06/07 16:47:56 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	get_pixel(const t_img *img, size_t index)
{
	size_t	real_index;
	t_color	color;

	real_index = index << 2;
	color.b = img->buf[real_index];
	color.g = img->buf[real_index + 1];
	color.r = img->buf[real_index + 2];
	color.a = img->buf[real_index + 3];
	return (color);
}

void	set_pixel(t_img *img, t_color color, size_t index)
{
	size_t	real_index;

	real_index = index << 2;
	img->buf[real_index] = color.b;
	img->buf[real_index + 1] = color.g;
	img->buf[real_index + 2] = color.r;
	img->buf[real_index + 3] = color.a;
}
