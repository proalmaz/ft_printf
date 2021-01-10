/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 13:46:09 by ckrommen          #+#    #+#             */
/*   Updated: 2020/12/28 17:59:18 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_unsigned_itoa(unsigned int nbr)
{
	int				length;
	unsigned int	for_len;
	char			*str;

	for_len = nbr;
	length = 1;
	while (for_len /= 10)
		length++;
	str = ft_strnew(length);
	if (!str)
		return (NULL);
	while (--length >= 0)
	{
		if (nbr >= 10)
			str[length] = (nbr % 10) + 48;
		else
			str[length] = nbr + 48;
		nbr /= 10;
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}
