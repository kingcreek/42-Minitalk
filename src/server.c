/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:21:28 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/08 10:58:39 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_helpers.h"

/**
 * It handles the signal by setting the bit of the character to be printed
 * 
 * @param signal The signal number that was received.
 */
void	handle_signal(int signal)
{
	if (signal == SIGUSR2)
		g_msg.c |= (0x01 << g_msg.i);
	if (g_msg.i == 7)
	{
		ft_printf("%c", g_msg.c);
		g_msg.c = 0;
		g_msg.i = -1;
	}
	g_msg.i++;
}

/**
 * It sets up a signal handler for SIGUSR1 and SIGUSR2, 
 * then waits for a signal to be sent
 * 
 * Print the PID of the server process.
 */
int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
	{
		pause ();
	}
	return (0);
}
