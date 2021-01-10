/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:02:53 by vping             #+#    #+#             */
/*   Updated: 2020/12/28 18:03:24 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_char(char c, t_flags flags)
{
	int	length;

	length = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	length = ft_int_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (length + 1);
}
