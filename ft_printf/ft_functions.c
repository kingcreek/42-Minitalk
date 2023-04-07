/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:01:54 by imurugar          #+#    #+#             */
/*   Updated: 2022/08/09 14:43:33 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_numbers(unsigned long long number, int base)
{
	int		count;

	count = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number = number / base;
		count++;
	}
	return (count);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (!s)
	{
		ft_putstr("(null)");
		return ;
	}
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
