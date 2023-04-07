/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:26:32 by imurugar          #+#    #+#             */
/*   Updated: 2022/08/09 16:37:19 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>

int		ft_printf(const char *str, ...);
char	*convert(unsigned long long num, int base, char cmd);
int		ft_count_numbers(unsigned long long number, int base);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_parser_hexadecimal(va_list arg, int *total_w, char step, int w_p[]);
void	ft_parser_pointer(va_list arg, int *total_w, char step, int w_p[]);
void	ft_parser_char(va_list arg, int *total_w, int w_p[]);
void	ft_parser_integer(va_list arg, int *total_w, char step, int w_p[]);
void	ft_parser_unsigned_integer(va_list arg, int *total_w,
			char step, int w_p[]);
void	ft_parser_octal(va_list arg, int *total_w, char step, int w_p[]);
void	ft_parser_string(va_list arg, int *total_w, int w_p[]);
size_t	ft_strlen(const char *str);
int		ft_isdigit(char c);

#endif