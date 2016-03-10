/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:42:35 by basle-qu          #+#    #+#             */
/*   Updated: 2016/03/09 15:22:25 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		main(void)
{
	t_data	anthill;

	anthill.start = NULL;
	anthill.end = NULL;
	if (verif_anthill(&anthill))
	{
		ft_putchar('\n');
		print_anthill(&anthill);
	}
	else
		ft_error("ERROR");
	return (0);
}
