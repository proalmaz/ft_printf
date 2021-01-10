/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:42:29 by vping             #+#    #+#             */
/*   Updated: 2020/12/29 20:21:08 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags		ft_strzero(void)
{
	t_flags	flags;

	flags.zero = 0;
	flags.minus = 0;
	flags.width = 0;
	flags.type = 0;
	flags.point = -1;
	flags.star = 0;
	return (flags);
}

int			ft_is_percent_or_type(int c)
{
	if (((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
				|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%')))
		return (1);
	else
		return (0);
}

int			ft_line_preprocessing(const char *str_for_parser, va_list args)
{
	int		i;
	int		length;
	t_flags	flags;

	i = 0;
	length = 0;
	while (str_for_parser[i] != '\0')
	{
		flags = ft_strzero();
		if (str_for_parser[i] != '%')
			length += ft_putchar((char)str_for_parser[i]);
		else if (str_for_parser[i] == '%' && str_for_parser[i + 1])
		{
			i = ft_parser_flag(str_for_parser, ++i, &flags, args);
			if (ft_is_percent_or_type(str_for_parser[i]))
				length += ft_parser_type((char)flags.type, flags, args);
			else if (str_for_parser[i])
				length += ft_putchar((char)str_for_parser[i]);
		}
		i++;
	}
	return (length);
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	int			length;
	const char	*tmp;

	length = 0;
	if (!(tmp = ft_strdup(format)))
		return (0);
	va_start(args, format);
	length += ft_line_preprocessing(tmp, args);
	va_end(args);
	free((char *)tmp);
	return (length);
}
