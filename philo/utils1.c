/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <dcastagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:07:41 by dcastagn          #+#    #+#             */
/*   Updated: 2023/04/20 15:54:00 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	size_t	num;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		sign = -1;
	else if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (num > 2147483647)
		return (-1);
	if (num < -2147483648)
		return (0);
	return (num * sign);
}

void	ft_bzero(void *a, size_t len)
{
	size_t			i;
	unsigned char	*tmp_a;

	i = 0;
	tmp_a = a;
	while (len > i)
	{
		tmp_a[i] = 0;
		i++;
	}
}
