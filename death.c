/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:25:02 by lohanyan          #+#    #+#             */
/*   Updated: 2022/11/30 15:17:31 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_death1(t_list *data, int n)
{
	long long	time;

	time = gettime();
	if (data->last_ate_time != -1)
	{
		time = time - data->last_ate_time;
		if (time > data->time_to_die)
			return (1);
	}
	else if (data->last_ate_time != 1 && n == 1)
	{
		time_to_eat_sleep(data->time_to_die);
		return (1);
	}
	return (0);
}

int	check_death2(char **argv, t_list **philo, int *die)
{
	int	n;
	int	i;

	n = ft_atoi(argv[1]);
	while (1)
	{
		i = 0;
		while (i < n)
		{
			if (check_death1(&(*philo)[i], n) == 0 &&
					check_six_arg(*philo, argv) != n)
				i++;
			else
			{
				if ((*philo)->flag_print == 0)
					print_info(&(*philo)[i], "died");
				*die = 0;
				return (0);
			}
		}
	}
}
