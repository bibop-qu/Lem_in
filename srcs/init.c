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

int		verif_anthill(t_data *anthill)
{
	char	*line;
	int		status;
	t_room	*room;

	line = NULL;
	room = NULL;
	status = 0;
	while (get_next_line(0, &line))
	{
		if (status == 0)
		{
			anthill->nbr_ant = ft_atoi(line);
			status = 1;
		}
		else if (status == 1 && anthill->nbr_ant < 1)
			ft_error("WRONG NUMBER OF ANTH !!");
		else if (status == 1 && verif_line_room(line) == 0)
			ft_error("BAD ROOM DECLARATION");
		else if (status == 1 && verif_line_room(line))
			room = ft_add_room(room, line);
	}
	anthill->room = room;
	return (1);
}
