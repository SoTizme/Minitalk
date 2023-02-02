/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 04:29:11 by shilal            #+#    #+#             */
/*   Updated: 2023/02/02 11:14:36 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(char *msg)
{
	write(1, "Error\n", 7);
	write(1, msg, ft_strlen(msg));
	exit (1);
}

int	is_dig(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!(pid[i] >= '0' && pid[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
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
		usleep(200);
	}
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;
	char	*str;

	if (ac != 3 || !av[2][0] || !av[1][0])
		ft_error("It's take 2 arguments \"PID\" \"Message\"\n");
	if (!is_dig(av[1]))
		ft_error("Invalid PID\n");
	pid = ft_atoi(av[1]);
	if (kill(pid, 0) || pid == 0)
		ft_error("Enter a valid PID\n");
	str = av[2];
	i = 0;
	while (str[i])
	{
		sendit(pid, str[i]);
		i++;
	}
	sendit(pid, '\n');
}
