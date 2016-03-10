/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 18:03:15 by basle-qu          #+#    #+#             */
/*   Updated: 2016/03/09 17:28:36 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

 int	init_pipe(t_pipe **pipe, t_room *room, char *line)
{
	if (verif_line_pipe(line, room))
		ft_add_pipe(*pipe, line, room);
	else if (!ft_strncmp(line, "#", 1))
		;
	else 
		return (0);
	while (get_next_line(0, &line) && (!ft_strncmp(line, "#", 1) || verif_line_pipe(line, room)))
	{
		if (!ft_strncmp(line, "#", 1))
			;
		else if (verif_line_pipe(line, room) == 0)
			return (0);
		else
			ft_add_pipe(*pipe, line, room);
	}
	return (1);
}

void	init_room(t_data *anthill, t_room **room, char **line)
{
	while (get_next_line(0, line) && (!ft_strncmp(*line, "#", 1) || verif_line_room(*line)))
	{
		if (!ft_strncmp(*line, "#", 1))
		{
			if ((!ft_strcmp(*line, "##start") && anthill->start != NULL) || (!ft_strcmp(*line, "##end") && anthill->end != NULL))
				ft_error("TWO START IS TO BAD");
			else if (!ft_strcmp(*line, "##start") && anthill->start == NULL)
			{
				get_next_line(0, line);
				if (verif_line_room(*line))
				{
					*room = ft_add_room(*room, *line);
					anthill->start = end_room(*room);
				}
				else
					ft_error("ERROR");
			}
			else if (!ft_strcmp(*line, "##end"))
			{
				get_next_line(0, line);
				if (verif_line_room(*line))
				{
					*room = ft_add_room(*room, *line);
					anthill->end = end_room(*room);	
				}
				else
					ft_error("ERROR");
			}
		}
		else
			*room = ft_add_room(*room, *line);
	}
}

int		verif_anthill(t_data *anthill)
{
	char	*line;
	t_room	*room;
	t_pipe	*pipe;

	line = NULL;
	room = NULL;
	pipe = NULL;
	get_next_line(0, &line);
	if (ft_strform(line, 1) && ft_atoi(line) > 0)
		anthill->nbr_ant = ft_atoi(line);
	else
		ft_error("WRONG NUMBER OF ANTH !!");
	init_room(anthill, &room, &line);
	if (anthill->start == NULL || anthill->end == NULL)
		ft_error("COME ON GIVE ME A START AND A END");
	init_pipe(&pipe, room, line);
//	ft_putendl(pipe->room_1->name);
	anthill->room = room;
	anthill->pipe = pipe;
	return (1);
}
