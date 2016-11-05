/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:42:35 by basle-qu          #+#    #+#             */
/*   Updated: 2016/03/15 18:52:00 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	print_walk(t_data *data);

void	init_option(int ac, char **av, t_data *anthill)
{
	int		i;
	
	anthill->o_d = 0;
	anthill->o_D = 0;
	anthill->o_e = 0;
	anthill->o_c = 0;
	anthill->o_m = 0;
	anthill->o_n = 0;
	anthill->o_p = 0;
	i = 1;
	while (ac && av[i])
	{
		if (!ft_strcmp(av[i], "-d"))
			anthill->o_d = 1;
		if (!ft_strcmp(av[i], "-D"))
			anthill->o_D = 1;
		if (!ft_strcmp(av[i], "-e"))
			anthill->o_e = 1;
		if (!ft_strcmp(av[i], "-c"))
			anthill->o_c = 1;
		if (!ft_strcmp(av[i], "-m"))
			anthill->o_m = 1;
		if (!ft_strcmp(av[i], "-n"))
			anthill->o_n = 1;
		if (!ft_strcmp(av[i], "-p"))
			anthill->o_p = 1;
		i++;
	}
}

int		main(int ac, char **av)
{
	t_data	anthill;

	anthill.start = NULL;
	anthill.end = NULL;
	anthill.nbr_turn = 0;
	init_option(ac, av, &anthill);
	if (init_anthill(&anthill))
		{
			resolve(&anthill);
			if (anthill.o_d || anthill.o_D || anthill.o_m || anthill.o_n || anthill.o_p)
				print_anthill(&anthill);
			ft_putchar('\n');
			if (!anthill.o_D)
				print_walk(&anthill);
			if (anthill.o_c)
			{
				ft_putendl("\033[1;32m======== NBR OF TURN ======\033[00m");
				ft_putnbr(anthill.nbr_turn);
				ft_putchar('\n');
			}
		}
	else
		ft_error("SOMETHING WRONG", &anthill);
	return (0);
}
