/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:48:47 by lohanyan          #+#    #+#             */
/*   Updated: 2022/11/30 13:34:10 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_parsing(char **argv, t_list **philo, int *die)
{
	int			i;
	int			n;

	n = ft_atoi(argv[1]);
	if (n < 1)
		return (1);
	*philo = malloc(sizeof(t_list) *(n));
	i = -1;
	if (!(*philo))
		return (0);
	while (++i < n)
	{
		(*philo)[i].last_ate_time = -1;
		(*philo)[i].eat_count = 0;
		(*philo)[i].die = die;
		(*philo)[i].flag_print = 0;
		(*philo)[i].time_to_die = ft_atoi(argv[2]);
		(*philo)[i].time_to_eat = ft_atoi(argv[3]);
		(*philo)[i].time_to_sleep = ft_atoi(argv[4]);
		if (argv[5] != NULL)
			(*philo)[i].count_of_eat = ft_atoi(argv[5]);
		else
			(*philo)[i].count_of_eat = -1;
	}
	return (0);
}

int	ft_check_error(char **argv)
{
	if (ft_digit(argv) == 0 || ft_check_negative(argv) == 0)
	{
		write(1, "error\n", 6);
		return (1);
	}
	return (0);
}
