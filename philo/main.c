/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <dcastagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:45:05 by dcastagn          #+#    #+#             */
/*   Updated: 2023/04/27 14:10:30 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_lonely_philo(t_philo	*philo)
{
	if (philo->id % 2 == 0)
		susleep(30);
	if (philo->data->number_of_philosophers == 1)
	{
		printf("%ld 1 has taken a fork\n",
			ft_current_time(philo->data->startime));
		susleep(philo->data->time_to_die);
	}
}

void	*ft_routine(void *filo)
{
	t_philo	*philo;

	philo = (t_philo *)filo;
	while (!philo->data->initall)
		;
	philo->starve_time = ft_current_time(0);
	ft_lonely_philo(philo);
	while (philo->data->death && philo->must_eat != 0)
	{
		ft_last_supper(philo);
		if (philo->data->death == 0)
			return (0);
		printf("%ld %d is sleeping\n",
			ft_current_time(philo->data->startime), philo->id);
		susleep(philo->data->time_to_sleep);
		if (philo->data->death == 0)
			return (0);
		printf("%ld %d is thinking\n",
			ft_current_time(philo->data->startime), philo->id);
	}
	return (0);
}

void	ft_last_supper(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	if (philo->data->death == 0)
			return ;
	printf("%ld %d has taken a fork\n",
		ft_current_time(philo->data->startime), philo->id);
	pthread_mutex_lock(&philo->next->fork);
	if (philo->data->death == 0)
			return ;
	printf("%ld %d has taken a fork\n",
		ft_current_time(philo->data->startime), philo->id);
	if (philo->data->death == 0)
			return ;
	printf("%ld %d is eating\n", ft_current_time(philo->data->startime),
		philo->id);
	philo->must_eat -= 1;
	philo->starve_time = ft_current_time(0);
	susleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

void	*ft_dead_or_alive(void *filo)
{
	t_philo	*philo;

	philo = (t_philo *)filo;
	susleep(50);
	while (42)
	{
		if (((ft_current_time(0) - philo->starve_time)
				>= philo->data->time_to_die || !philo->data->death)
			&& philo->must_eat != 0)
		{
			printf("%ld %d %sdied\n%s",
				ft_current_time(philo->data->startime), philo->id, YELLOW, NC);
			philo->data->death = 0;
			break ;
		}
		philo = philo->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	rules;
	t_philo	*philo;

	if (argc < 5 || argc > 6)
		return (printf("Error bad input\n"));
	if (check_args(argc, argv))
		return (printf("Invalid Input\n"));
	if (init(argc, argv, &rules))
		return (printf("you have exceeded the max/min int value\n"));
	rules.initall = 0;
	philo = init_philo(&rules);
	rules.initall = 1;
	init_thread(philo);
	join_threads(philo);
	free_all(philo);
	return (0);
}
