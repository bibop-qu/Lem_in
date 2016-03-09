/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:59:18 by basle-qu          #+#    #+#             */
/*   Updated: 2016/03/09 16:26:14 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_room		*ft_add_room(t_room *room, char *line)
{
	t_room	*new;
	t_room	*tmp;
	char	**tab;

	new = (t_room *)malloc(sizeof(t_room));
	tab = ft_strsplit(line, ' ');
	new->name = ft_strdup(tab[0]);
	new->pos_x = ft_atoi(tab[1]);
	new->pos_y = ft_atoi(tab[2]);
	new->next = NULL;
	tmp = room;
	free_tab(tab);
	if (room == NULL)
		return (new);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		return (room);
	}
}

t_pipe		*ft_add_pipe(t_pipe *pipe, char *line)
{
	t_pipe	*new;
	t_pipe	*tmp;
	char	**tab;

	new = (t_pipe *)malloc(sizeof(t_pipe));
	tab = ft_strsplit(line, '-');
	new->room_1 = ft_strdup(tab[0]);
	new->room_2 = ft_strdup(tab[1]);
	new->next = NULL;
	tmp = pipe;
	free_tab(tab);
	if (pipe == NULL)
		return (new);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		return (pipe);
	}
}

int		find_room(t_room *room, char *str)
{
	t_room	*tmp;

	tmp = room;
	while (tmp->next)
	{
		if (!ft_strcmp(room->name, str))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_room	*end_room(t_room *room)
{
	t_room	*tmp;

	tmp = room;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
