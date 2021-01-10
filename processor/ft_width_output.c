/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:20:29 by vping             #+#    #+#             */
/*   Updated: 2020/12/28 18:21:53 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_width_output(t_flags flags)
{
	int		length;

	length = 0;
	while (flags.width > flags.minus)
	{
		if (flags.zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		flags.width -= 1;
		length++;
	}
	return (length);
}

int		ft_int_width(int width, int minus, int zero)
{
	int		length;

	length = 0;
	while (width > minus)
	{
		zero ? ft_putchar('0') : ft_putchar(' ');
		width--;
		length++;
	}
	return (length);
}
