/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:20:03 by adelille          #+#    #+#             */
/*   Updated: 2025/05/29 18:31:01 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_pixel(t_img *img, t_color color, size_t index)
{
	size_t	real_index;

	real_index = index << 2;
	img->buf[real_index] = color.b;
	img->buf[real_index + 1] = color.g;
	img->buf[real_index + 2] = color.r;
	img->buf[real_index + 3] = color.a;
}
