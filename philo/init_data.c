/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <dcastagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:46:33 by dcastagn          #+#    #+#             */
/*   Updated: 2023/04/26 14:36:31 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init(int argc, char **argv, t_data *rules)
{
	rules->number_of_philosophers = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	rules->death = 1;
	rules->startime = ft_current_time(0);
	if (argc == 6)
		rules->must_eat = ft_atoi(argv[5]);
	else
		rules->must_eat = -2;
	if (rules->number_of_philosophers == -1
		|| rules->time_to_die == -1
		|| rules->time_to_eat == -1
		|| rules->time_to_sleep == -1
		|| rules->must_eat == -1)
		return (1);
	return (0);
}

t_philo	*init_philo(t_data *data)
{
	t_philo	*tmp;
	t_philo	*philo;
	int		i;

	philo = (t_philo *) malloc(sizeof(t_philo));
	tmp = philo;
	i = 0;
	while (i < data->number_of_philosophers)
	{
		philo->data = data;
		philo->id = i + 1;
		philo->must_eat = data->must_eat;
		if (i < data->number_of_philosophers - 1)
			philo->next = (t_philo *) malloc(sizeof(t_philo));
		else
			philo->next = tmp;
		pthread_mutex_init(&philo->fork, 0);
		philo = philo->next;
		i++;
	}
	philo = philo->next;
	return (philo);
}

void	init_thread(t_philo *philo)
{
	t_data		data;
	int			i;

	i = 0;
	while (i < philo->data->number_of_philosophers)
	{
		pthread_create(&philo->philot, NULL, ft_routine, (void *)philo);
		philo = philo->next;
		i++;
	}
	pthread_create(&data.phdoa, NULL, ft_dead_or_alive, (void *)philo);
}

void	join_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->number_of_philosophers)
	{
		pthread_join(philo->philot, NULL);
		i++;
	}
}
