
#include "lem-in.h"

t_map	*add_map(t_map *map, t_road *road)
{
	t_map	*new;
	t_map	*tmp;

	tmp = map;
	new = (t_map *)malloc(sizeof(t_map));
	new->road = road;
	new->next = NULL;
	new->size = 0;
	if (map == NULL)
		return (new);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (map);
}

t_road	*add_road_2(t_road *road, t_room *room)
{
	t_road	*new;
	t_road	*tmp;

	new = (t_road *)malloc(sizeof(t_road));
	new->room = room;
	new->next = NULL;
	if (road == NULL)
		return (new);
	tmp = road;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (road);
}

void	save_road(t_data *anthill, t_road *place)
{
	t_road	*cpy;
	t_road	*tmp;

	tmp = place;
	cpy = NULL;
	while (tmp)
	{
		cpy = add_road_2(cpy, tmp->room);
		tmp = tmp->next;
	}
	anthill->map = add_map(anthill->map, cpy);
}

t_road	*add_road(t_room *room)
{
	t_road	*new;

	new = (t_road *)malloc(sizeof(t_road));
	new->room = room;
	new->usd = 0;
	new->next = NULL;
	return (new);
}

void	cut_road(t_road *road)
{
	t_road	*tmp;

	tmp = road;
	if (tmp == NULL)
		return ;
	if (!tmp->next)
	{
		tmp->room = NULL;
		free(tmp);
		return ;
	}
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->room = NULL;
	free(tmp->next);
	tmp->next = NULL;

}

int	init_map(t_data *anthill, t_road *place, t_room *neigh)
{
 	t_road	*tmp;
	t_neigh	*tmp_2;

	tmp = place;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp == NULL)
		place = add_road(neigh);
	else
		tmp->next = add_road(neigh);
	if (tmp && tmp->next && !ft_strcmp(tmp->next->room->name,  anthill->end->name))
	{
		save_road(anthill, place);
		return (1);
	}
	tmp_2 = neigh->neighbors;
	while (tmp_2)
	{
		if (find_road(place, tmp_2->room->name) == NULL)
		{
			init_map(anthill, place, tmp_2->room);
			cut_road(place);
		}
		tmp_2 = tmp_2->next;
	}
	return (0);
}

