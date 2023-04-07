/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:23:27 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/06 17:40:20 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_helpers.h"

/**
 * It takes a string, and returns the integer value of that string
 * 
 * @param str The string to be converted.
 * 
 * @return The number of characters printed.
 */
int	ft_atoi(char *str)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = 1;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		ret = (ret * 10) + (*str - '0');
		str++;
	}
	return (ret * sign);
}

/**
 * It sends a byte to the process with the given id
 * 
 * @param id the pid of the process to send the message to
 * @param b the byte to send
 */
void	sig_send_msg(int id, unsigned char b)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((b >> bit) & 1)
		{
			if (kill(id, SIGUSR2) == -1)
			{
				ft_printf("Invalid pid\n");
				exit (0);
			}
		}
		else
		{
			if (kill(id, SIGUSR1) == -1)
			{
				ft_printf("Invalid pid\n");
				exit (0);
			}
		}
		bit++;
		usleep(300);
	}
}

/**
 * It sends a message to a process by sending a signal to it
 * 
 * @param argc The number of arguments passed to the program.
 * @param argv argv[0] = "./client"
 * 
 * @return The return value of the last function called.
 */
int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		while (*argv[2])
		{
			sig_send_msg(ft_atoi(argv[1]), *argv[2]);
			argv[2]++;
		}
		sig_send_msg(ft_atoi(argv[1]), *argv[2]);
		return (0);
	}
	ft_printf("Invalid arguments\nExpected: ./client [pid] [message]\n", signal);
	return (0);
}
