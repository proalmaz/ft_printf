/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_definition.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:49:36 by vping             #+#    #+#             */
/*   Updated: 2020/12/28 17:51:32 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags	ft_flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags	ft_flag_width(va_list args, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
		flags.zero = 0;
	}
	return (flags);
}

t_flags	ft_flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - 48);
	return (flags);
}

int		ft_flag_point(const char *str, int start,
		t_flags *flags, va_list args)
{
	int i;

	i = start;
	i++;
	if (str[i] == '*')
	{
		flags->point = va_arg(args, int);
		i++;
	}
	else
	{
		flags->point = 0;
		while (ft_isdigit(str[i]))
		{
			flags->point = (flags->point * 10) + (str[i] - 48);
			i++;
		}
	}
	return (i);
}
