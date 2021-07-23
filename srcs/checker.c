/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:25:45 by mlazzare          #+#    #+#             */
/*   Updated: 2021/07/21 15:06:31 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

static void	ft_cmd(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "sa"))
		ft_swap(*a, 0);
	else if (!ft_strcmp(line, "sb"))
		ft_swap(*b, 0);
	else if (!ft_strcmp(line, "ra"))
		ft_shiftup(a, 0);
	else if (!ft_strcmp(line, "rb"))
		ft_shiftup(b, 0);
}

static void	ft_cmd2(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "pa"))
	{
		ft_push(a, (*b)->num, 0);
		ft_pop(b, (*b)->num);
	}
	else if (!ft_strcmp(line, "pb"))
	{
		ft_push(b, (*a)->num, 0);
		ft_pop(a, (*a)->num);
	}
	else if (!ft_strcmp(line, "rr"))
		ft_rr(a, b, 0);
	else if (!ft_strcmp(line, "rrr"))
		ft_rrr(a, b, 0);
	else if (!ft_strcmp(line, "rra"))
		ft_shiftdown(a, 0);
	else
		ft_shiftdown(b, 0);
}

void	check_sorted(t_stack *a, int err, int l)
{
	if (err)
	{
		write(1, "Error\n", 6);
		ft_exit(a);
	}
	if (sorted(a) && l == get_stacksize(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static void	check_pushswap(t_stack **a, t_stack **b, int err, int ac)
{
	int		r;
	char	*line;
	int		l;

	l = get_stacksize(*a);
	r = get_next_line(&line);
	while (r && a && *a)
	{
		if (ac > 2)
		{
			if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "sb")
				|| !ft_strcmp(line, "ra") || !ft_strcmp(line, "rb"))
				ft_cmd(line, a, b);
			else if (!ft_strcmp(line, "pa") || !ft_strcmp(line, "pb")
				|| !ft_strcmp(line, "rr") || !ft_strcmp(line, "rrr")
				|| !ft_strcmp(line, "rrb") || !ft_strcmp(line, "rra"))
				ft_cmd2(line, a, b);
			else
				err = 1;
		}
		free(line);
		r = get_next_line(&line);
	}
	free(line);
	check_sorted(*a, err, l);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		l;
	int		err;

	if (argc != 1)
	{
		err = 0;
		l = argc - 1;
		a = NULL;
		if (!fill_stack(l, argc, argv, &a))
		{
			write(1, "Error\n", 6);
			free_stack(&a);
			return (0);
		}
		b = NULL;
		check_pushswap(&a, &b, err, argc);
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}
