/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:44:34 by mlazzare          #+#    #+#             */
/*   Updated: 2021/05/13 19:57:20 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

int main(int argc, char **argv)
{
    int *a;
    int *b;
    int l;

    if (argc == 1 || argc > 2)
        printf("Error\n");
    else
    {
        l = input_length(argv[1]);
        a = malloc(sizeof(int) * l);
        if (!a)
            return (0);
        b = malloc(sizeof(int) * l);
        if (!b)
            return (0);
        pushswap(argv[1], a, b);        
    }
    free (a);
    free (b);
    return (0);
}