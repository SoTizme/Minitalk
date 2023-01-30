/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:57:53 by shilal            #+#    #+#             */
/*   Updated: 2023/01/30 19:19:25 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigint(int sig)
{
	static int		i;
	static char		c;

	if (sig == SIGUSR1)
		c |= 1;
	if (i++ == 7)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	c <<= 1;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "The PID of this process is : ", 30);
	ft_putnbr(pid);
	write(1, "\n", 1);
	write(1, "Waiting...\n", 12);
	while (1)
	{	
		signal(SIGUSR1, handle_sigint);
		signal(SIGUSR2, handle_sigint);
		pause();
	}
}
