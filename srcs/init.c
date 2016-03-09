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

void	init_pipe(t_pipe **pipe, t_room *room, char *line)
{
	ft_putendl(line);
	if (verif_line_pipe(line, room))
		*pipe = ft_add_pipe(*pipe, line);
	ft_putstr((*pipe)->room_1);
	ft_putchar('\n');
	while (get_next_line(0, &line))
	{
		if (!ft_strncmp(line, "#", 1))
			;
		else if (verif_line_pipe(line, room))
			*pipe = ft_add_pipe(*pipe, line);
		else
			break;
	}
}

void	init_room(t_data *anthill, t_room **room, char **line)
{
	while (get_next_line(0, line) && (!ft_strncmp(*line, "#", 1) || verif_line_room(*line)))
	{
		if (!ft_strncmp(*line, "#", 1))
		{
			if (!ft_strcmp(*line, "##start"))
			{
				get_next_line(0, line);
				*room = ft_add_room(*room, *line);
				anthill->start = end_room(*room);
			}
			else if (!ft_strcmp(*line, "##end"))
			{
				get_next_line(0, line);
				*room = ft_add_room(*room, *line);
				anthill->end = end_room(*room);
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
	if (anthill->start = NULL || anthill->end == NULL)
		ft_error("COME ON GIVE ME A START AND A END");
	init_pipe(&pipe, room, line);
	anthill->room = room;
	anthill->pipe = pipe;
	return (1);
}
