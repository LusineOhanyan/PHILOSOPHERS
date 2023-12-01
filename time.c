/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:14:11 by lohanyan          #+#    #+#             */
/*   Updated: 2022/11/30 13:26:47 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	gettime(void)
{
	long long		mili;
	struct timeval	start;

	gettimeofday(&start, NULL);
	mili = start.tv_sec * 1000 + start.tv_usec / 1000;
	return (mili);
}

void	time_to_eat_sleep(int x)
{
	long long	time;

	time = gettime();
	while ((gettime() - time) < x)
		usleep(100);
}

void	print_info(t_list *data, char *s)
{
	long long	time;

	if (*(data->die) == 1)
	{
		time = gettime() - data->starttime;
		printf("%lld %d %s\n", time, data->philo_index, s);
	}
}

int	check_six_arg(t_list *philo, char **argv)
{
	int	count;
	int	i;
	int	n;

	count = 0;
	i = 0;
	n = ft_atoi(argv[1]);
	while (i < n)
	{
		if (philo[i].eat_count >= philo->count_of_eat
			&& philo->count_of_eat != -1)
			count++;
		i++;
	}
	if (count == n)
		philo->flag_print = 1;
	return (count);
}
