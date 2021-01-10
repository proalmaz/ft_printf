/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:51:55 by vping             #+#    #+#             */
/*   Updated: 2020/12/28 17:55:33 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_is_flag(int c)
{
	if ((c == '.') || (c == '*') || (c == '0') || (c == '-') || (c == ' '))
		return (1);
	else
		return (0);
}

int		ft_parser_flag(const char *str, int i, t_flags *flags, va_list args)
{
	while (str[i])
	{
		if (!ft_is_percent_or_type(str[i]) &&
				!ft_is_flag(str[i]) && !ft_isdigit(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '*')
			*flags = ft_flag_width(args, *flags);
		if (str[i] == '.')
			i = ft_flag_point(str, i, flags, args);
		if (str[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (ft_isdigit(str[i]))
			*flags = ft_flag_digit(str[i], *flags);
		if (ft_is_percent_or_type(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

int		ft_parser_type(int c, t_flags flags, va_list args)
{
	int		length;

	length = 0;
	if (c == 'c')
		length = ft_char(va_arg(args, int), flags);
	else if (c == '%')
		length += ft_percent(flags);
	else if (c == 'p')
		length = ft_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 's')
		length = ft_string(va_arg(args, char *), flags);
	else if ((c == 'd') || (c == 'i'))
		length = ft_int(va_arg(args, int), flags);
	else if (c == 'x')
		length += ft_hex(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		length += ft_hex(va_arg(args, unsigned int), 0, flags);
	else if (c == 'u')
		length += ft_unsigned_int(va_arg(args, unsigned int), flags);
	return (length);
}
