/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:42:35 by basle-qu          #+#    #+#             */
/*   Updated: 2016/03/07 19:45:04 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		main(void)
{
	t_data	anthill;

	if (verif_anthill(&anthill))
	{
		ft_putnbr(anthill.nbr_ant);
		ft_putchar('\n');
		ft_putendl(anthill.room->name);
	}
	else
		ft_error("ERROR");
	return (0);
}
