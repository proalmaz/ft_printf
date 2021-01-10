/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:09:17 by vping             #+#    #+#             */
/*   Updated: 2020/12/28 18:10:20 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_hex_minus(char *hex, t_flags flags)
{
	int		length;

	length = 0;
	if (flags.point >= 0)
		length += ft_int_width(flags.point - 1, ft_strlen(hex) - 1, 1);
	length += ft_string_output_prec(hex, ft_strlen(hex));
	return (length);
}

int		ft_hex_output(char *hex, t_flags flags)
{
	int		length;

	length = 0;
	if (flags.minus == 1)
		length += ft_hex_minus(hex, flags);
	if (flags.point >= 0 && (size_t)flags.point < ft_strlen(hex))
		flags.point = ft_strlen(hex);
	if (flags.point >= 0)
	{
		flags.width -= flags.point;
		length += ft_int_width(flags.width, 0, 0);
	}
	else
		length += ft_int_width(flags.width, ft_strlen(hex), flags.zero);
	if (flags.minus == 0)
		length += ft_hex_minus(hex, flags);
	return (length);
}

int		ft_hex(unsigned int digit, int lowercase, t_flags flags)
{
	char	*hex;
	int		length;

	length = 0;
	if (flags.point == 0 && digit == 0)
	{
		length += ft_int_width(flags.width, 0, 0);
		return (length);
	}
	hex = ft_converter((unsigned long long)digit, 16);
	lowercase == 1 ? hex = ft_str_tolower(hex) : hex;
	length += ft_hex_output(hex, flags);
	free(hex);
	return (length);
}
