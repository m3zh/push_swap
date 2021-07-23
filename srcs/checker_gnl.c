/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:26:49 by mlazzare          #+#    #+#             */
/*   Updated: 2021/07/19 18:54:46 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

static void	update_tmp(char *tmp, char **line, char c, int l)
{
	int	i;

	i = -1;
	while (++i < (l - 2))
		tmp[i] = (*line)[i];
	tmp[i] = c;
	tmp[i + 1] = 0;
	free(*line);
	*line = tmp;
}

int	get_next_line(char **line)
{
	int		l;
	int		r;
	char	c;
	char	*tmp;

	l = 1;
	*line = malloc(sizeof(char) * l);
	if (!*line)
		return (-1);
	(*line)[0] = 0;
	r = read(0, &c, 1);
	while (r && l++ && c != '\n')
	{
		tmp = malloc(sizeof(char) * l);
		if (!tmp)
		{
			if (*line)
				free (line);
			return (-1);
		}
		update_tmp(tmp, line, c, l);
		r = read(0, &c, 1);
	}
	return (r);
}
