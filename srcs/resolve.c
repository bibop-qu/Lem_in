/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:49:18 by basle-qu          #+#    #+#             */
/*   Updated: 2016/03/17 22:35:35 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_map	*add_map_2(t_map *cpy, t_map *map)
{
	t_map	*new;
	t_map	*tmp;

	tmp = map;
	new = (t_map *)malloc(sizeof(t_map));
	new->road = map->road;
	new->next = NULL;
	if (cpy == NULL)
		return (new);
	while (tmp)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

void	save_road(t_data *anthill, t_map *place)
{
	ft_putendl("DOIGT TORDU");
	t_map	*cpy;
	t_map	*tmp;

	tmp = place;
	cpy = (t_map *)malloc(sizeof(t_map));
	while (tmp)
	{
		cpy = add_map_2(cpy, tmp);
		tmp = tmp->next;
	}
	anthill->map = cpy;
}

t_map	*add_map(t_room *room)
{
	t_map	*new;

	new = (t_map *)malloc(sizeof(t_map));
	new->road = room;
	new->next = NULL;
	return (new);
}

int	init_map(t_data *anthill, t_map *place, t_room *neigh)
{
	t_map	*tmp;
	t_neigh	*tmp_2;

	tmp = place;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp == NULL)
		place = add_map(neigh);
	else
		tmp->next = add_map(neigh);
	if (tmp && !ft_strcmp(place->road->name,  anthill->end->name))
	{
		save_road(anthill, place);
		return (1);
	}
	tmp_2 = neigh->neighbors;
	while (tmp_2)
	{
		if (find_room(place->road, tmp_2->room->name) == NULL)
		{
			ft_putendl("LOL");
			init_map(anthill, place, tmp_2->room);
		}
		else
		{
			ft_putendl("RETURN 0");
			return (0);
		}
		tmp_2 = tmp_2->next;
	}
	return (0);
}


t_neigh	*add_neigh(t_neigh *neighbors, t_room *room)
{
	t_neigh		*new;
	t_neigh		*tmp;

	tmp = neighbors;
	new = (t_neigh *)malloc(sizeof(t_neigh));
	new->room = room;
	new->next = NULL;
	if (neighbors == NULL)
		return (new);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		return (neighbors);
	}
}

void	init_neighbour(t_data *anthill)
{
	t_pipe	*tmp;

	tmp = anthill->pipe;
	while (tmp)
	{
		tmp->room_1->neighbors = add_neigh(tmp->room_1->neighbors, tmp->room_2);
		tmp->room_2->neighbors = add_neigh(tmp->room_2->neighbors, tmp->room_1);
		tmp = tmp->next;
	}
}

int		resolve(t_data *anthill)
{
	anthill->map = NULL;
	init_neighbour(anthill);
	init_map(anthill, NULL, anthill->start);
	return (0);
}
