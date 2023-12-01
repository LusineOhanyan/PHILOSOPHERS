/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:08:28 by lohanyan          #+#    #+#             */
/*   Updated: 2022/11/29 18:00:39 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	ft_digit(char **str)
{
	int	i;
	int	k;

	i = 0;
	k = 1;
	while (str && str[k])
	{
		i = 0;
		if (str[k][i] == '-' || str[k][i] == '+')
			i++;
		if (str[k][i] == '\0')
			return (0);
		while (str[k][i])
		{
			if (str[k][i] >= 48 && str[k][i] <= 57)
				i++;
			else
				return (0);
		}	
		k++;
	}
	return (1);
}

int	ft_check_negative(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == -1)
			return (0);
		i++;
	}
	return (1);
}
