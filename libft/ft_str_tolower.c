/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:48:48 by vping             #+#    #+#             */
/*   Updated: 2020/12/20 16:49:13 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_tolower(char *string)
{
	int		i;

	i = 0;
	while (string[i])
	{
		string[i] = (char)ft_tolower(string[i]);
		i++;
	}
	return (string);
}
