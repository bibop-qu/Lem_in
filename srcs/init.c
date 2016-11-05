/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 18:03:15 by basle-qu          #+#    #+#             */
/*   Updated: 2016/03/11 15:44:13 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		init_pipe(t_pipe **pipe, t_room *room, char *line)
{
	if (!ft_strncmp(line, "#", 1))
		;
	else if (verif_line_pipe(line, room))
		*pipe = ft_add_pipe(*pipe, line, room);
	else
		return (0);
	ft_putendl(line);
	while (get_next_line(0, &line) && (!ft_strncmp(line, "#", 1) ||
								verif_line_pipe(line, room)))
	{
		ft_putendl(line);
		if (!ft_strncmp(line, "#", 1))
			;
		else if (verif_line_pipe(line, room) && !exist_pipe(*pipe, line))
			*pipe = ft_add_pipe(*pipe, line, room);
		else
			return (0);
	}
	return (0);
}

void	init_ext(t_data *anthill, t_room **room, char **line)
{
	if (!ft_strcmp(*line, "##start") && anthill->start == NULL)
	{
		get_next_line(0, line);
		if (verif_line_room(*line) && !exist_room(*room, *line))
		{
			*room = ft_add_room(*room, *line);
			anthill->start = end_room(*room);
		}
		else
			ft_error("ERROR WITH START", anthill);
		ft_putendl(*line);
	}
	else if (!ft_strcmp(*line, "##end"))
	{
		get_next_line(0, line);
		if (verif_line_room(*line) && !exist_room(*room, *line))
		{
			*room = ft_add_room(*room, *line);
			anthill->end = end_room(*room);
		}
		else
			ft_error("ERROR WITH END", anthill);
		ft_putendl(*line);
	}
}

void	init_room(t_data *anthill, t_room **room, char **line)
{
	ft_putendl(*line);
	while (get_next_line(0, line) && (!ft_strncmp(*line, "#", 1) ||
								verif_line_room(*line)))
	{
		ft_putendl(*line);
		if (!ft_strncmp(*line, "#", 1))
		{
			if ((!ft_strcmp(*line, "##start") && anthill->start != NULL) ||
				(!ft_strcmp(*line, "##end") && anthill->end != NULL))
				ft_error("NEED JUST ONE START AND ONE END", anthill);
			else
				init_ext(anthill, room, line);
		}
		else if (!exist_room(*room, *line))
			*room = ft_add_room(*room, *line);
		else
			ft_error("ERROR", anthill);
	}
}

int		init_anthill(t_data *anthill)
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
		ft_error("WRONG NUMBER OF ANTH !!", anthill);
	init_room(anthill, &room, &line);
	if (!room)
		ft_error("NO ROOM REALLY ?!!", anthill);
	if (!anthill->start || !anthill->end)
		ft_error("COME ON GIVE ME A START AND A END BUDY !!", anthill);
	init_pipe(&pipe, room, line);
	if (!pipe)
		ft_error("COME ON GIVE ME A PIPE AT LEAST BUDY !!", anthill);
	anthill->room = room;
	anthill->pipe = pipe;
	return (1);
}
