/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:58:39 by adelille          #+#    #+#             */
/*   Updated: 2025/06/07 21:33:24 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_uint16(uint8_t *buf, size_t offset, uint16_t value)
{
	buf[offset] = (uint8_t)(value & 0xFF);
	buf[offset + 1] = (uint8_t)((value >> 8) & 0xFF);
}

static void	set_uint32(uint8_t *buf, size_t offset, uint32_t value)
{
	buf[offset] = (uint8_t)(value & 0xFF);
	buf[offset + 1] = (uint8_t)((value >> 8) & 0xFF);
	buf[offset + 2] = (uint8_t)((value >> 16) & 0xFF);
	buf[offset + 3] = (uint8_t)((value >> 24) & 0xFF);
}

void	write_bmp_header(const t_env *env, int fd, uint32_t pixel_size)
{
	uint8_t		header[122];
	uint32_t	file_size;

	ft_bzero(header, sizeof(header));
	file_size = 122 + pixel_size;
	header[0] = 'B';
	header[1] = 'M';
	set_uint32(header, 2, file_size);
	set_uint32(header, 10, 122);
	set_uint32(header, 14, 108);
	set_uint32(header, 18, (uint32_t)(env->win.w));
	set_uint32(header, 22, (uint32_t)(-env->win.h));
	set_uint16(header, 26, 1);
	set_uint16(header, 28, 32);
	set_uint32(header, 30, 3);
	set_uint32(header, 34, pixel_size);
	set_uint32(header, 54, 0x00FF0000);
	set_uint32(header, 58, 0x0000FF00);
	set_uint32(header, 62, 0x000000FF);
	set_uint32(header, 66, 0xFF000000);
	set_uint32(header, 70, 0x57696E20);
	(void)write(fd, header, sizeof(header));
}
