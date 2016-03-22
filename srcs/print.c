/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:11:25 by basle-qu          #+#    #+#             */
/*   Updated: 2016/03/18 17:57:23 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	print_start(t_data *anthill)
{
	ft_putendl("\033[1;31m##start\033[00m");
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
		}
		tmp = tmp->next;
	}
}

void	print_end(t_data *anthill)
{
	ft_putendl("\033[1;31m##end\033[00m");
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

	tmp = anthill->room;
	ft_putendl("\033[1;32m======== NEIGHBORS ======\033[00m");
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
	t_road	*tmp_2;

	tmp = anthill->map;
	ft_putendl("\033[1;32m=========== MAP =========\033[00m");
	while(tmp)
	{
		tmp_2 = tmp->road;
		while (tmp_2)
		{
			ft_putstr(tmp_2->room->name);
			if (tmp_2->next)
				ft_putstr("->");
			else
			{
				ft_putstr(": ");
				ft_putnbr(tmp->size);
			}
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
	ft_putendl("\033[1;32m========== DATA =========\033[00m");
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
	print_neighbors(anthill);
	print_map(anthill);
}
