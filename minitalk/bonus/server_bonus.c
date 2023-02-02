/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:05:58 by shilal            #+#    #+#             */
/*   Updated: 2023/01/31 15:19:08 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_catcher(int sig, siginfo_t *s, void *str)
{
	static int				i;
	static unsigned char	c;

	(void)str;
	if (sig == SIGUSR1)
		c |= 1;
	if (i++ == 7)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	c <<= 1;
	if (i == 0)
	{
		usleep(1000);
		kill(s->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	act;
	int					pid;

	pid = getpid();
	write(1, "The PID of this process is : ", 30);
	ft_putnbr(pid);
	write(1, "\n", 1);
	write(1, "Waiting...\n", 12);
	act.sa_sigaction = signal_catcher;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
}
