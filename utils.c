/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:16:43 by lohanyan          #+#    #+#             */
/*   Updated: 2022/11/30 12:55:59 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	ft_atoi(char *str)
{
	int	index;
	int	value;

	index = 0;
	value = 0;
	while (str[index] == 32 || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			return (-1);
		index++;
	}	
	while (str[index] >= '0' && str[index] <= '9')
	{
		value = value * 10 + str[index] - '0';
		index++;
	}
	return (value);
}
