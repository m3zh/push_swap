/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 08:05:31 by mlazzare          #+#    #+#             */
/*   Updated: 2021/05/13 19:55:57 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

static int	check_overflow(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int						i;
	int						sign;
	unsigned long long int	n;

	i = 0;
	n = 0;
	sign = 1;
	while (str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = check_sign(str[i++]);
	if (ft_isalpha(str[i]))
	{
		printf("Error\n");
		exit (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (n >= MAX_LONG)
		{
			printf("Error\n");
			exit (0);
		}
		n = n * 10 + (str[i++] - '0');
	}
	return (sign * (int)n);
}
