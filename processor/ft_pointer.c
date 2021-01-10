/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:11:14 by vping             #+#    #+#             */
/*   Updated: 2020/12/28 18:19:05 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_pointer_output(char *pointer, t_flags flags)
{
	int		length;

	length = 0;
	length += ft_string_output_prec("0x", 2);
	if (flags.point >= 0)
	{
		length += ft_int_width(flags.point, ft_strlen(pointer), 1);
		length += ft_string_output_prec(pointer, flags.point);
	}
	else
		length += ft_string_output_prec(pointer, ft_strlen(pointer));
	return (length);
}

int		ft_pointer(unsigned long long digit, t_flags flags)
{
	int		length;
	char	*c;

	length = 0;
	if (flags.point == 0 && !digit)
	{
		if (flags.minus != 0 && flags.width < 0)
		{
			length += ft_string_output_prec("0x", 2);
			length += ft_int_width(flags.width - 2, 0, 0);
		}
		else
		{
			length += ft_int_width(flags.width - 2, 0, 0);
			length += ft_string_output_prec("0x", 2);
		}
		return (length);
	}
	c = ft_str_tolower(ft_converter(digit, 16));
	(size_t)flags.point < ft_strlen(c) ? flags.point = ft_strlen(c) : 1;
	flags.minus == 1 ? length += ft_pointer_output(c, flags) : length;
	length += ft_int_width(flags.width, ft_strlen(c) + 2, 0);
	flags.minus == 0 ? length += ft_pointer_output(c, flags) : length;
	free(c);
	return (length);
}
