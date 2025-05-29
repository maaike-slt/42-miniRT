/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:12:54 by msloot            #+#    #+#             */
/*   Updated: 2025/05/29 22:49:09 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parse.h"

static bool	parse_color_bit(
	const t_line_arg *la, const char *str, t_color_bit *color)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (puterr_invalid_int(la, str, 0, UCHAR_MAX), false);
		i++;
	}
	if (i > 3)
		return (puterr_invalid_int(la, str, 0, UCHAR_MAX), false);
	*color = ft_atoun(str);
	if (*color > UCHAR_MAX)
		return (puterr_invalid_int(la, str, 0, UCHAR_MAX), false);
	return (true);
}

bool	parse_color(const t_line_arg *la, const char *str, t_color *color)
{
	char	**split;
	size_t	len;

	split = ft_split_any_of(str, ",");
	if (!split)
		return (false);
	len = ft_2d_size((const void **)split);
	if (len != 3)
	{
		ft_2d_free((void ***)&split, len);
		puterr_invalid_sub_token_amount(
			la, str, (t_expected_got){3, len}, "<x,y,z>");
		return (false);
	}
	if (!parse_color_bit(la, split[0], &(color->r))
		|| !parse_color_bit(la, split[1], &(color->g))
		|| !parse_color_bit(la, split[2], &(color->b)))
		return (ft_2d_free((void ***)&split, len), false);
	ft_2d_free((void ***)&split, len);
	return (true);
}
