/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:51:22 by imurugar          #+#    #+#             */
/*   Updated: 2022/08/09 17:24:33 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parser_hexadecimal(va_list arg, int *total_w,
		char step, int w_p[])
{
	long long	i;
	int			len;

	i = va_arg(arg, unsigned int);
	len = w_p[0] - ft_count_numbers(i, 16);
	while (len-- > 0)
	{
		ft_putchar(' ');
		*total_w += 1;
	}
	ft_putstr(convert(i, 16, step));
	*total_w += ft_count_numbers(i, 16);
}

void	ft_parser_pointer(va_list arg, int *total_w, char step, int w_p[])
{
	long long	i;
	int			len;

	i = (unsigned long long)va_arg(arg, void *);
	len = w_p[0] - ft_count_numbers(i, 16);
	while (len-- > 0)
	{
		ft_putchar(' ');
		*total_w += 1;
	}
	ft_putstr("0x");
	ft_putstr(convert(i, 16, step));
	*total_w += ft_count_numbers(i, 16) + 2;
}
