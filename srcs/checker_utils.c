/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:27:00 by mlazzare          #+#    #+#             */
/*   Updated: 2021/07/20 15:33:43 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	ft_rrr(t_stack **a, t_stack **b, char c)
{
	ft_shiftup(a, c);
	ft_shiftup(b, c);
}

void	ft_rr(t_stack **a, t_stack **b, char c)
{
	ft_shiftdown(a, c);
	ft_shiftdown(b, c);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i]
					- ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
