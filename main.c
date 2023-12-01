/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:15:58 by lohanyan          #+#    #+#             */
/*   Updated: 2022/11/30 15:17:33 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	*f(void *argp)
{
	t_list	*philo;

	philo = (t_list *)argp;
	if (philo->philo_index % 2 == 0)
		usleep(200);
	philo->starttime = gettime();
	philo->last_ate_time = gettime();
	while (1)
	{
		pthread_mutex_lock(philo->right);
		print_info(philo, "has taken right fork");
		pthread_mutex_lock(philo->left);
		print_info(philo, "has taken left fork");
		print_info(philo, "is eating");
		philo->last_ate_time = gettime();
		time_to_eat_sleep(philo->time_to_eat);
		philo->eat_count++;
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		print_info(philo, "is sleeping");
		time_to_eat_sleep(philo->time_to_sleep);
		print_info(philo, "is thinking");
	}
	return (NULL);
}

void	count(t_list *data)
{
	static int	counter;

	data->philo_index = counter + 1;
	counter++;
}

pthread_t	*ft_philo(char **argv, t_list **data)
{
	int				i;
	int				n;
	pthread_t		*id;
	pthread_mutex_t	*mutex;

	n = ft_atoi(argv[1]);
	id = malloc(sizeof(pthread_t) * n);
	mutex = malloc(sizeof(pthread_mutex_t) * n);
	i = -1;
	while (++i < n)
		pthread_mutex_init(&mutex[i], NULL);
	i = -1;
	value_of_fork(data, argv, &mutex);
	while (++i < n)
	{
		count(&(*data)[i]);
		pthread_create(&id[i], NULL, f, &(*data)[i]);
	}
	return (id);
}

void	value_of_fork(t_list **data, char **argv, pthread_mutex_t **mutex)
{
	int	i;
	int	n;

	i = 0;
	n = ft_atoi(argv[1]);
	while (i < n)
	{
		(*data)[i].fork = *mutex;
		if (i == n - 1)
			(*data)[i].left = &((*mutex)[0]);
		else
			(*data)[i].left = &((*mutex)[i + 1]);
		(*data)[i].right = &((*mutex)[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list		*philo;
	int			i;
	int			die;
	int			n;
	pthread_t	*id;

	i = 0;
	die = 1;
	id = NULL;
	philo = NULL;
	if (argc == 5 || argc == 6)
	{
		n = ft_atoi(argv[1]);
		if (ft_parsing(argv, &philo, &die) == 1 || ft_check_error(argv) == 1)
			return (0);
		id = ft_philo(argv, &philo);
		check_death2(argv, &philo, &die);
		free(id);
		free(philo->fork);
		free(philo);
	}
	else
		write(1, "error\n", 6);
}
