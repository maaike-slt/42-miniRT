/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:33:54 by adelille          #+#    #+#             */
/*   Updated: 2025/06/07 17:33:52 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_img	copy(const t_img *src)
{
	t_img	copy;

	copy.ptr = src->ptr;
	copy.buf = src->buf;
	copy.bpp = src->bpp;
	copy.size_line = src->size_line;
	copy.endian = src->endian;
	return (copy);
}

// skip alpha for optimization
static size_t	fetch_sum_pixel(
	const t_env *env, uint16_t *sum, size_t x, size_t y)
{
	t_color	pixel;

	pixel = get_pixel(&(env->rd.original_pov), y * env->win.w + x);
	sum[0] += pixel.r;
	sum[1] += pixel.g;
	sum[2] += pixel.b;
	return (1);
}

static size_t	fetch_sum_pixel_neighbors(
	const t_env *env, uint16_t *sum, size_t x, size_t y)
{
	size_t	count;

	count = 0;
	if (x > 0)
	{
		if (y > 0)
			count += fetch_sum_pixel(env, sum, x - 1, y - 1);
		count += fetch_sum_pixel(env, sum, x - 1, y);
		if (y < env->win.h - 1)
			count += fetch_sum_pixel(env, sum, x - 1, y + 1);
	}
	if (y > 0)
		count += fetch_sum_pixel(env, sum, x, y - 1);
	if (y < env->win.h - 1)
		count += fetch_sum_pixel(env, sum, x, y + 1);
	if (x < env->win.w - 1)
	{
		if (y > 0)
			count += fetch_sum_pixel(env, sum, x + 1, y - 1);
		count += fetch_sum_pixel(env, sum, x + 1, y);
		if (y < env->win.h - 1)
			count += fetch_sum_pixel(env, sum, x + 1, y + 1);
	}
	return (count);
}

void	apply_pixel_anti_aliasing(t_env *env, size_t x, size_t y)
{
	t_color		original;
	uint16_t	sum[3];
	size_t		index;
	size_t		count;

	index = y * env->win.w + x;
	original = get_pixel(&(env->rd.original_pov), index);
	sum[0] = original.r;
	sum[1] = original.g;
	sum[2] = original.b;
	count = 1 + fetch_sum_pixel_neighbors(env, sum, x, y);
	set_pixel(&(env->pov[env->pov_index]), (t_color){
		.r = (t_color_bit)(sum[0] / count),
		.g = (t_color_bit)(sum[1] / count),
		.b = (t_color_bit)(sum[2] / count),
		.a = original.a,
	}, index);
}

void	apply_anti_aliasing(t_env *env)
{
	env->rd.original_pov = copy(&(env->pov[env->pov_index]));
	env->pov[env->pov_index].ptr = \
mlx_new_image(env->mlx, env->win.w, env->win.h);
	if (!env->pov[env->pov_index].ptr)
	{
		env->pov[env->pov_index].ptr = env->rd.original_pov.ptr;
		return ;
	}
	env->pov[env->pov_index].buf = (t_color_bit *)mlx_get_data_addr(
			env->pov[env->pov_index].ptr,
			&(env->pov[env->pov_index].bpp),
			&(env->pov[env->pov_index].size_line),
			&(env->pov[env->pov_index].endian));
	ft_memcpy(env->pov[env->pov_index].buf,
		env->rd.original_pov.buf,
		env->win.w * env->win.h * (sizeof(t_color_bit) * 4));
	reverse_transversal_anti_aliasing(env);
	mlx_destroy_image(env->mlx, env->rd.original_pov.ptr);
}
