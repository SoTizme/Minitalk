/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:16:41 by shilal            #+#    #+#             */
/*   Updated: 2023/01/30 15:39:48 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/minitalk.h"
#include "../bonus/minitalk_bonus.h"

size_t	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
