/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <dcastagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:45:05 by dcastagn          #+#    #+#             */
/*   Updated: 2023/04/25 15:54:57 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_lonely_philo(t_philo	*philo)
{
	if (philo->id % 2 == 0)
		usleep(20 * 1000);
	if (philo->data->number_of_philosophers == 1)
	
}
void	*ft_routine(void *filo)
{
	t_philo	*philo;

	philo = (t_philo *)filo;
	philo->starve_time = ft_current_time(0);
	ft_lonely_philo(philo);
	while (philo->data->death && philo->eating_done_count != 0)
	{
		pthread_mutex_lock(&philo->fork);
		usleep(100);
		printf("%lld %d has taken a fork\n", ft_current_time(philo->data->startime), philo->id);
		pthread_mutex_lock(&philo->next->fork);
		usleep(100);
		printf("%lld %d has taken a fork\n", ft_current_time(philo->data->startime), philo->id);
		usleep(100);
		printf("%lld %d is eating\n", ft_current_time(philo->data->startime), philo->id);
		philo->must_eat -= 1;
		philo->starve_time = ft_current_time(0);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		usleep(100);
		printf("%lld %d is sleeping\n", ft_current_time(philo->data->startime), philo->id);
		usleep((philo->data->time_to_sleep * 1000) + 100);
		printf("%lld %d is thinking\n", ft_current_time(philo->data->startime), philo->id);
	}
}

void	*ft_dead_or_alive(void *filo)
{
	t_philo	*philo;

	philo = (t_philo *)filo;
	while (42)
	{
		if ((ft_current_time(0) - philo->starve_time) >= philo->data->time_to_die)
		{
			printf("%lld %d died\n", ft_current_time(philo->data->startime), philo->id);
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

	if (argc < 5 || argc > 6)
		return (printf("Error bad input\n"));
	if (check_args(argc, argv))
		return (printf("Invalid Input\n"));
	if (init(argc, argv, &rules))
		return (printf("you have exceeded the max/min int value\n"));
	return (0);
}
