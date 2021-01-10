/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:03:44 by vping             #+#    #+#             */
/*   Updated: 2020/12/28 18:07:23 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_int_output_2(char *number, int c, t_flags flags)
{
	int		length;

	length = 0;
	if (flags.point >= 0 && c < 0 && c != -2147483648)
		length += ft_putchar('-');
	if (flags.point >= 0)
		length += ft_int_width(flags.point - 1, ft_strlen(number) - 1, 1);
	length += ft_string_output_prec(number, ft_strlen(number));
	return (length);
}

int		ft_int_output(char *number, int c, t_flags flags)
{
	int		length;

	length = 0;
	if (flags.minus == 1)
		length += ft_int_output_2(number, c, flags);
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
		length += ft_int_output_2(number, c, flags);
	free(number);
	return (length);
}

int		ft_int(int c, t_flags flags)
{
	int		length;
	int		num;

	length = 0;
	num = c;
	if (flags.point == 0 && c == 0)
	{
		length += ft_int_width(flags.width, 0, 0);
		return (length);
	}
	if (c < 0 && (flags.point >= 0 || flags.zero == 1) && c != -2147483648)
	{
		if (flags.point <= -1 && flags.zero == 1)
		{
			ft_string_output_prec("-", 1);
			length++;
		}
		c *= -1;
		flags.zero = 1;
		flags.width--;
	}
	length += ft_int_output(ft_itoa(c), num, flags);
	return (length);
}
