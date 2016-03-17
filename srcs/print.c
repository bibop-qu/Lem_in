/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:11:25 by basle-qu          #+#    #+#             */
/*   Updated: 2016/03/17 21:48:51 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	print_start(t_data *anthill)
{
	ft_putendl("##start");
	ft_putstr(anthill->start->name);
	ft_putchar(' ');
	ft_putnbr(anthill->start->pos_x);
	ft_putchar(' ');
	ft_putnbr(anthill->start->pos_y);
	ft_putchar('\n');
}

void	print_room(t_data *anthill)
{
	t_room	*tmp;

	tmp = anthill->room;
	while (tmp)
	{
		if (tmp != anthill->start && tmp != anthill->end)
		{
			ft_putstr(tmp->name);
			ft_putchar(' ');
			ft_putnbr(tmp->pos_x);
			ft_putchar(' ');
			ft_putnbr(tmp->pos_y);
			ft_putchar('\n');
			tmp = tmp->next;
		}
		tmp = tmp->next;
	}
}

void	print_end(t_data *anthill)
{
	ft_putendl("##end");
	ft_putstr(anthill->end->name);
	ft_putchar(' ');
	ft_putnbr(anthill->end->pos_x);
	ft_putchar(' ');
	ft_putnbr(anthill->end->pos_y);
	ft_putchar('\n');
}

void	print_neighbors(t_data *anthill)
{
	t_room	*tmp;
	t_neigh	*lol;

	tmp = anthill->start;
	ft_putendl("======== NEIGHBORS ======");
	while (tmp)
	{
		lol = tmp->neighbors;
		ft_putstr(tmp->name);
		ft_putstr(": ");
		while (lol)
		{
			ft_putstr(lol->room->name);
			if (lol->next)
				ft_putstr(", ");
			lol = lol->next;
		}
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

void	print_map(t_data *anthill)
{
	t_map	*tmp;
	t_room	*tmp_2;

	tmp = anthill->map;
	ft_putendl("========== MAP ========");
	while(tmp)
	{
		tmp_2 = tmp->road;
		while (tmp_2)
		{
			ft_putstr(tmp_2->name);
			if (tmp->next)
				ft_putstr("->");
			tmp_2 = tmp_2->next;
		}
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

void	print_anthill(t_data *anthill)
{
	t_pipe	*tmp_pipe;

	tmp_pipe = anthill->pipe;
	ft_putchar('\n');
	ft_putendl("======== DATA ========");
	ft_putchar('\n');
	if (anthill->nbr_ant)
	{
		ft_putnbr(anthill->nbr_ant);
		ft_putchar('\n');
	}
	print_start(anthill);
	print_room(anthill);
	print_end(anthill);
	while (tmp_pipe)
	{
		ft_putstr(tmp_pipe->room_1->name);
		ft_putchar('-');
		ft_putstr(tmp_pipe->room_2->name);
		ft_putchar('\n');
		tmp_pipe = tmp_pipe->next;
	}
	ft_putchar('\n');
	print_neighbors(anthill);
	print_map(anthill);
}
