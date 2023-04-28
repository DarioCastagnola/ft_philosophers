/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <dcastagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:51:52 by dcastagn          #+#    #+#             */
/*   Updated: 2023/04/27 12:23:29 by dcastagn         ###   ########.fr       */
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
	pthread_t		phdoa;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				mstime;
	long			startime;
	int				must_eat;
	int				death;
	int				initall;
}	t_data;

typedef struct s_philo
{
	pthread_mutex_t	fork;
	struct s_philo	*next;
	pthread_t		philot;
	t_data			*data;
	int				id;
	long			starve_time;
	int				must_eat;
}	t_philo;

int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			check_args(int argc, char **argv);
int			init(int argc, char **argv, t_data *rules);
t_philo		*init_philo(t_data *data);
void		init_thread(t_philo *philo);
void		join_threads(t_philo *philo);
void		ft_lonely_philo(t_philo	*philo);
void		*ft_routine(void *filo);
void		*ft_dead_or_alive(void *filo);
long		ft_current_time(long n);
void		free_all(t_philo *philo);
void		susleep(int ms);
void		ft_last_supper(t_philo	*philo);

#endif
