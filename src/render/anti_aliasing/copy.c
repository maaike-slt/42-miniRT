/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:30:23 by adelille          #+#    #+#             */
/*   Updated: 2025/06/07 17:30:35 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_img	img_copy(const t_img *src)
{
	t_img	copy;

	copy.ptr = src->ptr;
	copy.buf = src->buf;
	copy.bpp = src->bpp;
	copy.size_line = src->size_line;
	copy.endian = src->endian;
	return (copy);
}

void	img_buffer_copy(t_img *dst, const t_img *src)
{
	if (dst->buf && src->buf)
		ft_memcpy(dst->buf, src->buf, dst->size_line * dst->endian);
	else
		puterr();
}
