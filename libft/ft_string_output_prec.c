/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_output_prec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:49:47 by vping             #+#    #+#             */
/*   Updated: 2020/12/28 17:57:43 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_string_output_prec(char *string, int precision)
{
	int		i;

	i = 0;
	while (string[i] != '\0' && i < precision)
	{
		ft_putchar(string[i]);
		i++;
	}
	return (i);
}
