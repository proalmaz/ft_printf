/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:19:30 by vping             #+#    #+#             */
/*   Updated: 2020/12/28 18:20:12 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_uint_output_2(char *number, t_flags flags)
{
	int		length;

	length = 0;
	if (flags.point >= 0)
		length += ft_int_width(flags.point - 1, ft_strlen(number) - 1, 1);
	length += ft_string_output_prec(number, ft_strlen(number));
	return (length);
}

int		ft_uint_output(char *number, t_flags flags)
{
	int		length;

	length = 0;
	if (flags.minus == 1)
		length += ft_uint_output_2(number, flags);
	if (flags.point >= 0 && (size_t)flags.point < ft_strlen(number))
		flags.point = ft_strlen(number);
	if (flags.point >= 0)
	{
		flags.width -= flags.point;
		length += ft_int_width(flags.width, 0, 0);
	}
	else
		length += ft_int_width(flags.width, ft_strlen(number), flags.zero);
	if (flags.minus == 0)
		length += ft_uint_output_2(number, flags);
	return (length);
}

int		ft_unsigned_int(unsigned int c, t_flags flags)
{
	int		length;
	char	*number;

	length = 0;
	if (flags.point == 0 && c == 0)
	{
		length += ft_int_width(flags.width, 0, 0);
		return (length);
	}
	number = ft_unsigned_itoa(c);
	length += ft_uint_output(number, flags);
	free(number);
	return (length);
}
