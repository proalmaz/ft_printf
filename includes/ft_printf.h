/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vping <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:43:58 by vping             #+#    #+#             */
/*   Updated: 2020/12/28 17:48:49 by vping            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_flags
{
	int		zero;
	int		minus;
	int		width;
	int		star;
	char	type;
	int		point;
}				t_flags;

int				ft_parser_flag(const char *str, int i,
		t_flags *flags, va_list args);
int				ft_printf(const char *format, ...);
int				ft_is_percent_or_type(int c);
int				ft_is_flag(int c);
t_flags			ft_flag_width(va_list args, t_flags flags);
t_flags			ft_flag_digit(char c, t_flags flags);
int				ft_width_output(t_flags flags);
int				ft_parser_type(int c, t_flags flags, va_list args);
int				ft_line_preprocessing(const char *str_for_parser, va_list args);
t_flags			ft_flag_minus(t_flags flags);
int				ft_flag_point(const char *str, int start, t_flags *flags,
		va_list args);
t_flags			ft_strzero();
int				ft_char(char c, t_flags flags);
int				ft_string(char *string, t_flags flags);
int				ft_str_output(char *string, t_flags flags);
int				ft_percent(t_flags flags);
int				ft_int(int c, t_flags flags);
int				ft_int_output(char *number, int c, t_flags flags);
int				ft_int_output_2(char *number, int c, t_flags flags);
int				ft_int_width(int width, int minus, int zero);
int				ft_unsigned_int(unsigned int c, t_flags flags);
int				ft_uint_output(char *number, t_flags flags);
int				ft_uint_output_2(char *number, t_flags flags);
int				ft_pointer(unsigned long long digit, t_flags flags);
int				ft_pointer_output(char *pointer, t_flags flags);
int				ft_hex(unsigned int digit, int lowercase, t_flags flags);
int				ft_hex_output(char *hex, t_flags flags);
int				ft_hex_minus(char *hex, t_flags flags);

#endif
