/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <dcastagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:51:52 by dcastagn          #+#    #+#             */
/*   Updated: 2023/04/25 15:00:35 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/time.h>
# define NC	"\e[0m"
# define YELLOW	"\e[1;33m"

typedef struct s_data
{
	pthread_t	phdoa;
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_sleep;
	int			time_to_eat;
	int			mstime;
	int			startime;
	int			must_eat;
	int			death;
}	t_data;

typedef struct s_philo
{
	pthread_mutex_t	fork;
	struct s_philo	*next;
	pthread_t		philot;
	t_data			*data;
	int				id;
	int				starve_time;
	int				eating_done_count;
	int				must_eat;
}	t_philo;

int	ft_atoi(const char *str);

#endif
