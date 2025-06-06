/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:32:05 by msloot            #+#    #+#             */
/*   Updated: 2025/06/07 00:11:29 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_env	env;

	if (argc != 2)
		return (puterr_argc(), 64);
	if (!init(&env))
		return (free_env(&env));
	if (!parse(&env, argv[1]))
		return (free_env(&env));
	if (!init_pov(&env))
		return (free_env(&env));
	render(&env);
	if (!create_window(&env))
		return (free_env(&env));
	set_hook(&env);
	mlx_loop(env.mlx);
	free_env(&env);
	return (0);
}
