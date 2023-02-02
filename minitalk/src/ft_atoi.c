/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:56:19 by shilal            #+#    #+#             */
/*   Updated: 2023/01/30 21:56:27 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/minitalk.h"
#include "../bonus/minitalk_bonus.h"

int	ft_isdigit(int a)
{
	if (a >= 48 && a <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	char	*ptr;
	size_t	i;
	size_t	nb;
	int		sign;

	ptr = (char *)str;
	i = 0;
	sign = 1;
	nb = 0;
	while (ptr[i] == ' ' || ptr[i] == '\r' || ptr[i] == '\t' || ptr[i] == '\n'
		|| ptr[i] == '\v' || ptr[i] == '\f')
		i++;
	if (ptr[i] == '+' || ptr[i] == '-')
	{
		if (ptr[i++] == '-')
			sign = -1;
	}
	while (ft_isdigit(ptr[i]))
	{
		nb = nb * 10 + (ptr[i] - 48);
		i++;
	}
	return (nb * sign);
}
