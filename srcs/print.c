/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:11:25 by basle-qu          #+#    #+#             */
/*   Updated: 2016/03/09 15:23:24 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	print_anthill(t_data *anthill)
{
	t_room	*tmp_room;
	t_pipe	*tmp_pipe;

	tmp_room = anthill->room;
	tmp_pipe = anthill->pipe;
	if (anthill->nbr_ant)
	{
		ft_putnbr(anthill->nbr_ant);
		ft_putchar('\n');
	}
	while (tmp_room)
	{
		ft_putstr(tmp_room->name);
		ft_putchar(' ');
		ft_putnbr(tmp_room->pos_x);
		ft_putchar(' ');
		ft_putnbr(tmp_room->pos_y);
		ft_putchar('\n');
		tmp_room = tmp_room->next;
	}
	// while (tmp_pipe)
	// {
	// 	ft_putstr(tmp_pipe->room_1);
	// 	ft_putchar('-');
	// 	ft_putstr(tmp_pipe->room_2);
	// 	ft_putchar('\n');
	// 	tmp_pipe = tmp_pipe->next;
	// }
}
