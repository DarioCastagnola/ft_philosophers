/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <dcastagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:45:05 by dcastagn          #+#    #+#             */
/*   Updated: 2023/04/24 11:37:58 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	ft_current_time(void)
{
	struct timeval	tv;
	long long		ms_time;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
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
