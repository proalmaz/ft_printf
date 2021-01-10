/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:37:12 by vping             #+#    #+#             */
/*   Updated: 2020/12/28 18:02:06 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include "../includes/ft_printf.h"

size_t				ft_strlen(const char *str);
int					ft_putchar(char c);
int					ft_isdigit(int c);
int					ft_string_output_prec(char *string, int precision);
char				*ft_strdup(const char *src);
char				*ft_itoa(int nbr);
char				*ft_unsigned_itoa(unsigned int nbr);
char				*ft_strnew(size_t size);
void				ft_bzero(void *s, size_t n);
int					ft_tolower(int c);
char				*ft_str_tolower(char *string);
char				*ft_converter(unsigned long long digit, int base);
char				*ft_base(unsigned long long digit, int base,
		int length, char *str);

#endif
