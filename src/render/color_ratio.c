/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ratio.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:07:13 by adelille          #+#    #+#             */
/*   Updated: 2025/06/07 23:44:32 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* (color ratio)
 Converts a color value from t_color_bit (0-255) to a float (0.0-1.0).

 @param c The color value in t_color_bit format.
 @return The color value as a float.
*/
float	cr(t_color_bit c)
{
	return ((float)c / 255.0f);
}

/* (color ratio reverse)
 Converts a float color value (0.0-1.0) to t_color_bit (0-255).

 @param c The color value as a float.
 @return The color value in t_color_bit format.
*/
t_color_bit	crr(float c)
{
	return ((t_color_bit)(c * 255.0f));
}
