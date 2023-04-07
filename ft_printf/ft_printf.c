/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 05:14:18 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/05 05:15:17 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert(unsigned long long num, int base, char cmd)
{
	char		*hex;
	static char	buffer[50];
	char		*ptr;

	hex = "0123456789abcdef";
	if (cmd == 'X')
		hex = "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
		*--ptr = hex[num % base];
	while (num != 0)
	{
		*--ptr = hex[num % base];
		num /= base;
	}
	return (ptr);
}

void	ft_parse_arg(char step, va_list arg, int *total, int w_p[])
{
	if (step == 'c')
		ft_parser_char(arg, total, w_p);
	else if (step == 'd' || step == 'i')
		ft_parser_integer(arg, total, step, w_p);
	else if (step == 'u')
		ft_parser_unsigned_integer(arg, total, step, w_p);
	else if (step == 'o')
		ft_parser_octal(arg, total, step, w_p);
	else if (step == 's')
		ft_parser_string(arg, total, w_p);
	else if (step == 'x' || step == 'X')
		ft_parser_hexadecimal(arg, total, step, w_p);
	else if (step == 'p')
		ft_parser_pointer(arg, total, step, w_p);
	else
	{
		ft_putchar(step);
		*total += 1;
	}
}

const char	*ft_check_flags_or_width(const char *str, int w_p[])
{
	int	i;

	w_p[0] = 0;
	w_p[1] = 0;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		w_p[0] = (w_p[0] * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]))
		{
			w_p[1] = (w_p[1] * 10) + (str[i] - '0');
			i++;
		}
	}
	str += i;
	return (str);
}

int	ft_printf(const char *str, ...)
{
	int				total_w;
	va_list			arg;
	int				w_p[2];

	total_w = 0;
	va_start(arg, str);
	while (*str != '\0')
	{
		while (*str != '%')
		{
			if (*str == '\0')
				return (total_w);
			ft_putchar(*str);
			str++;
			total_w++;
		}
		str++;
		str = ft_check_flags_or_width(str, w_p);
		ft_parse_arg(*str, arg, &total_w, w_p);
		str++;
	}
	va_end(arg);
	return (total_w);
}
