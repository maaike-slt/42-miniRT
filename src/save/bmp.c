/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:40:14 by adelille          #+#    #+#             */
/*   Updated: 2025/06/10 11:39:58 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	*get_output_path(const t_env *env)
{
	char	*path;
	size_t	len;
	size_t	i;

	i = 0;
	if (ft_strncmp(env->file, "./", 2) == 0)
		i = 2;
	if (ft_strncmp(env->file + i, "input/", 6) == 0)
		i += 6;
	path = ft_strjoin(OUTPUT_PATH, env->file + i);
	if (!path)
		return (NULL);
	len = ft_strlen(path);
	if (env->scene.c_amt > 1)
	{
		path[len - 3] = '-';
		path[len - 2] = '\0';
		path = ft_strjoin_free(path, ft_untoa(env->pov_index), true, true);
		if (!path)
			return (NULL);
	}
	else
		path[len - 3] = '\0';
	path = ft_strjoin_free(path, ".bmp", true, false);
	return (path);
}

static void	puterr_cannot_open_bmp(void)
{
	puterr();
	ft_putstr_fd("cannot open bmp file:\n", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	save_pov(const t_env *env)
{
	char		*path;
	int			fd;
	size_t		pixel_size;

	pixel_size = env->win.w * env->win.h * sizeof(t_color_bit) * 4;
	if (env->win.w > UINT_MAX || env->win.h > UINT_MAX
		|| pixel_size + BMP_HEADER_SIZE > UINT_MAX)
	{
		puterr();
		ft_putstr_fd("cannot save pov as bmp, resolution is too big\n",
			STDERR_FILENO);
		return ;
	}
	path = get_output_path(env);
	if (!path)
		return ;
	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	free(path);
	if (fd < 0)
		return (puterr_cannot_open_bmp());
	write_bmp_header(env, fd, (uint32_t)pixel_size);
	(void)!write(fd, env->pov[env->pov_index].buf, pixel_size);
	close(fd);
}
