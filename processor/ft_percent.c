/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:10:36 by vping             #+#    #+#             */
/*   Updated: 2020/12/28 18:10:59 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_percent(t_flags flags)
{
	int		length;

	length = 0;
	if (flags.minus == 1)
		length += ft_putchar('%');
	length += ft_int_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		length += ft_putchar('%');
	return (length);
}
