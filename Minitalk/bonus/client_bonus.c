/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:00:41 by shilal            #+#    #+#             */
/*   Updated: 2023/01/30 21:10:54 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_error(char *msg)
{
	write(1, "Error\n", 7);
	write(1, msg, ft_strlen(msg));
	exit (1);
}

void	sendit(int pid, char s)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if ((s & (1 << j)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		j--;
		usleep(500);
	}
}

void	handal_sig(int sig)
{
	if (sig == SIGUSR1)
		write(1, "The message is sending...\n", 27);
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;
	char	*str;

	if (ac != 3 || !av[2][0] || !av[1][0])
		ft_error("It's take 2 arguments \"PID\" \"Message\"\n");
	pid = ft_atoi(av[1]);
	if (kill(pid, 0) || pid == 0)
		ft_error("Enter a valid PID\n");
	str = av[2];
	i = 0;
	while (str[i])
	{
		sendit(pid, str[i]);
		signal(SIGUSR1, handal_sig);
		pause();
		i++;
	}
	sendit(pid, '\n');
}
