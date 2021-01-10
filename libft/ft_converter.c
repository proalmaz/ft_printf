/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:59:56 by vping             #+#    #+#             */
/*   Updated: 2020/12/28 18:00:50 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_base(unsigned long long digit, int base,
		int length, char *str)
{
	while (digit)
	{
		if ((digit % base) >= 10)
			str[length - 1] = (digit % base) + 55;
		else
			str[length - 1] = (digit % base) + 48;
		digit /= base;
		length--;
	}
	return (str);
}

char	*ft_converter(unsigned long long digit, int base)
{
	int						length;
	unsigned long long		tmp;
	char					*str;

	length = 0;
	tmp = digit;
	if (!digit)
		return (ft_strdup("0"));
	while (tmp)
	{
		tmp /= base;
		length++;
	}
	if (!(str = malloc(length + 1)))
		return (0);
	str[length] = '\0';
	str = ft_base(digit, base, length, str);
	return (str);
}
