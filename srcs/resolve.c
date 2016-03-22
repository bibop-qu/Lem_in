/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:49:18 by basle-qu          #+#    #+#             */
/*   Updated: 2016/03/22 15:45:21 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

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
	int	nb_road;

	nb_road = 0;
	anthill->map = NULL;
	init_neighbour(anthill);
	init_map(anthill, NULL, anthill->start);
	if (!anthill->map)
		ft_error("NO ROAD BETWEEN START AND END, TRY AGAIN !!");
	size_road(anthill);
	sort_map(anthill);
	nb_road = best_neighbors(anthill->start, anthill->end);
	do_lem_in(anthill);
	return (0);
}
