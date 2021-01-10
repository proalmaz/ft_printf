/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:08:32 by vping             #+#    #+#             */
/*   Updated: 2020/12/28 18:09:01 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_str_output(char *string, t_flags flags)
{
	int		length;

	length = 0;
	if (flags.point >= 0)
	{
		length += ft_int_width(flags.point, ft_strlen(string), 0);
		length += ft_string_output_prec(string, flags.point);
	}
	else
		length += ft_string_output_prec(string, ft_strlen(string));
	return (length);
}

int		ft_string(char *string, t_flags flags)
{
	int		length;

	length = 0;
	if (!string)
		string = "(null)";
	if (flags.point >= 0 && (size_t)flags.point > ft_strlen(string))
		flags.point = ft_strlen(string);
	if (flags.minus == 1)
		length += ft_str_output(string, flags);
	if (flags.point >= 0)
		length += ft_int_width(flags.width, flags.point, 0);
	else
		length += ft_int_width(flags.width, ft_strlen(string), 0);
	if (flags.minus == 0)
		length += ft_str_output(string, flags);
	return (length);
}
