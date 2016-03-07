/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:48:53 by basle-qu          #+#    #+#             */
/*   Updated: 2016/03/07 18:12:22 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_error(char *error)
{
	ft_putendl(error);
	exit(1);
}

void	print_anthill(char **anthill)
{
	int		i;

	i = 0;
	while (anthill[i])
	{
		ft_putendl(anthill[i]);
		i++;
	}
}
