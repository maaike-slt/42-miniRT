/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:32:05 by msloot            #+#    #+#             */
/*   Updated: 2025/05/22 22:01:09 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_env	env;

	(void)argv;
	if (argc != 2)
		return (ft_puterr(
				"not the right amount of files, 1 file shall be given\n"), 1);
	if (!init(&env))
		return (free_env(&env));

//	if (!parse(&env, argv[1]))
//		return (free_env(&env));
	env.scene.cam_amt = 1;

	if (!init_pov(&env))
		return (free_env(&env));
//	if (!render(&env))
//		return (free_env(&env));

	create_window(&env);
//	if (!create_window(&env))
//		return (free_spr(&env) && free_env(&env));
	set_hook(&env);
	mlx_loop(env.mlx);
	free_env(&env);
	return (0);
}
