/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:16:15 by lohanyan          #+#    #+#             */
/*   Updated: 2022/11/29 17:36:23 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_list
{
	int				*die;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philo_index;
	long long		starttime;
	long long		last_ate_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	long long		start;
	int				count_of_eat;
	int				eat_count;
	int				flag_print;	
}	t_list;
int			ft_atoi(char *str);
void		count(t_list *data);
int			ft_digit(char **str);
int			ft_check_negative(char **argv);
pthread_t	*ft_philo(char **argv, t_list **data);
void		value_of_fork(t_list **data, char **argv, pthread_mutex_t **mutex);
long long	gettime(void);
void		time_to_eat_sleep(int x);
void		print_info(t_list *data, char *s);
int			check_death1(t_list *data, int n);
int			check_death2(char **argv, t_list **philo, int *die);
int			ft_parsing(char **argv, t_list **philo, int *die);
int			ft_check_error(char **argv);
int			check_six_arg(t_list *philo, char **argv);
#endif
