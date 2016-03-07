/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 18:03:15 by basle-qu          #+#    #+#             */
/*   Updated: 2016/03/07 19:28:38 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	verif_anthill(t_data *anthill)
{
	char	*line;
	int		status;

	line = NULL;
	status = 0;
	while (get_next_line(0, &line))
	{
		if (status == 0)
		{
			anthill->nbr_ant = ft_atoi(line);
			status = 1;
		}
	}
}
