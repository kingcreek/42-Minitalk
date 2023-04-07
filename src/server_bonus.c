/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:21:28 by imurugar          #+#    #+#             */
/*   Updated: 2023/02/08 10:58:16 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_helpers.h"

/**
 * It handles the signal
 * 
 * @param signal The signal number that was sent.
 * @param info a pointer to a siginfo_t structure.
 * @param context This is a pointer to a ucontext_t structure. 
 * This structure contains the entire
 * machine state at the time of the signal.
 */
void	handle_signal(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (signal == SIGUSR2)
		g_msg.c |= (0x01 << g_msg.i);
	kill(info->si_pid, SIGUSR2);
	if (g_msg.i == 7)
	{
		ft_printf("%c", g_msg.c);
		g_msg.c = 0;
		g_msg.i = -1;
	}
	g_msg.i++;
}

/**
 * `sigaction` is used to set the signal handler for the 
 * `SIGUSR1` and `SIGUSR2` signals
 * 
 * @return The PID of the server process.
 */
int	main(void)
{
	struct sigaction	act;

	ft_printf("Server PID: %d\n", getpid());
	act.sa_sigaction = handle_signal;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
		pause ();
	}
	return (0);
}
