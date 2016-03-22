/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:02:15 by basle-qu          #+#    #+#             */
/*   Updated: 2016/03/22 15:02:17 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		init_size(t_road *road)
{
	t_road	*tmp;
	int		i;

	i = 0;
	tmp = road;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i - 1);
}

void	size_road(t_data *anthill)
{
	t_map	*tmp;

	tmp = anthill->map;
	while (tmp)
	{
		tmp->size = init_size(tmp->road);
		tmp = tmp->next;
	}
}


void	switch_map(t_map *m1, t_map *m2)
{
	t_road	*tmp_road;
	int		tmp_size;

	tmp_road = m1->road;
	tmp_size = m1->size;
	m1->road = m2->road;
	m1->size = m2->size;
	m2->road = tmp_road;
	m2->size = tmp_size;
}

void	sort_map(t_data	*anthill)
{
	t_map	*tmp;
	int		nb_map;
	int		i;

	nb_map = 0;
	i = 0;
	tmp = anthill->map;
	while (tmp && ++nb_map >0)
		tmp = tmp->next;
	while (++i < nb_map)
	{
		tmp = anthill->map;
		while (tmp && tmp->next)
		{
			if (tmp->size > tmp->next->size)
				switch_map(tmp, tmp->next);
			tmp = tmp->next;
		}
	}
}
