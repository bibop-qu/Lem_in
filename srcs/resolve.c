/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:49:18 by basle-qu          #+#    #+#             */
/*   Updated: 2016/03/11 19:07:53 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_room	*ft_cpy_room(t_room *begin, t_room	*room)
{
	t_room	*tmp;
	t_room	*new;

	tmp = begin;
	new = (t_room *)malloc(sizeof(t_room));
	new->name = ft_strdup(room->name);
	new->pos_x = room->pos_x;
	new->pos_y = room->pos_y;
	new->next = NULL;
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

void	create_road(t_data *anthill, t_road **road, t_pipe *ref)
{
	t_pipe	*tmp;
	t_room	*begin;
	int		i;

	i = 0;
	begin = ft_cpy_room(begin, anthill->start);
	if (ref->room_1 != anthill->start)
		begin = ft_cpy_room(begin, ref->room_1);
	else
		begin = ft_cpy_room(begin, ref->room_2);
	while (i < size_pipe(anthill->pipe))
	{
		tmp = anthill->pipe;
		while (tmp)
		{

			tmp = tmp->next;
		}
		i++;
	}
}

void	init_road(t_data *anthill, t_road **road)
{
	t_pipe	*tmp;

	tmp = anthill->pipe;
	while (tmp)
	{
		if (tmp->room_1 == anthill->start || tmp->room_2 == anthill->start)
			create_road(anthill, road, tmp);
		tmp = tmp->next;
	}
}

int		resolve(t_data *anthill)
{
	t_road	*road;

	road = NULL;
	init_road(anthill, &road);
	return (0);
}
