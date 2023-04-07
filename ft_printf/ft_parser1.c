/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:51:14 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/05 05:13:30 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parser_char(va_list arg, int *total_w, int w_p[])
{
	long long	i;
	int			len;

	i = va_arg(arg, int);
	len = w_p[0] - 1;
	while (len-- > 0)
	{
		ft_putchar(' ');
		*total_w += 1;
	}
	ft_putchar(i);
	*total_w += 1;
}

void	ft_parser_integer(va_list arg, int *total_w, char step, int w_p[])
{
	long long	i;
	int			len;

	i = va_arg(arg, int);
	len = w_p[0] - ft_count_numbers(i, 10);
	while (len-- > 0)
	{
		ft_putchar(' ');
		*total_w += 1;
	}
	if (i < 0)
	{
		i = i * -1;
		ft_putchar('-');
		*total_w += 1;
	}
	ft_putstr(convert(i, 10, step));
	*total_w += ft_count_numbers(i, 10);
}

void	ft_parser_unsigned_integer(va_list arg, int *total_w,
		char step, int w_p[])
{
	long long	i;
	int			len;

	i = va_arg(arg, unsigned int);
	len = w_p[0] - ft_count_numbers((unsigned long)i, 10);
	while (len-- > 0)
	{
		ft_putchar(' ');
		*total_w += 1;
	}
	ft_putstr(convert((unsigned long)i, 10, step));
	*total_w += ft_count_numbers((unsigned long)i, 10);
}

void	ft_parser_octal(va_list arg, int *total_w, char step, int w_p[])
{
	long long	i;
	int			len;

	i = va_arg(arg, unsigned int);
	len = w_p[0] - ft_count_numbers(i, 8);
	while (len-- > 0)
	{
		ft_putchar(' ');
		*total_w += 1;
	}
	ft_putstr(convert(i, 8, step));
	*total_w += ft_count_numbers(i, 8);
}

void	ft_parser_string(va_list arg, int *total_w, int w_p[])
{
	char	*s;
	int		len;

	s = va_arg(arg, char *);
	if (w_p[1])
		s += w_p[1];
	len = w_p[0] - ft_strlen(s);
	while (len-- > 0)
	{
		ft_putchar(' ');
		*total_w += 1;
	}
	ft_putstr(s);
	*total_w += ft_strlen(s);
	if (!s)
		*total_w += ft_strlen("(null)");
}
