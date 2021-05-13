/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:19:57 by mlazzare          #+#    #+#             */
/*   Updated: 2021/05/13 20:00:54 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

int check_input(char *input, int *a)
{
    int i;
    int j;

    i = -1;
    j = 0;
    while(input[j])
    {
        while (input[j] == ' ')
            j++;
        a[++i] = ft_atoi(&input[j]);
    }
    return (0);
}

int input_length(char *input)
{
    int i;

    i = 1;
    if (!ft_strcmp(input, ""))
    {
        printf("Error\n");
        exit(0);
    }
    while(*input)
    {
        while (*input == ' ')
            input++;
        i++;
    }
    return (0);
}