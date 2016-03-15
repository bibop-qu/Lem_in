/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 18:56:52 by basle-qu          #+#    #+#             */
/*   Updated: 2016/03/15 17:58:16 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_neigh t_neigh;

typedef struct		s_room
{
	char			*name;
	int				pos_x;
	int				pos_y;
	t_neigh			*neighbors;
	struct s_room	*next;
}					t_room;

typedef struct		s_pipe
{
	t_room			*room_1;
	t_room			*room_2;
	struct s_pipe	*next;
}					t_pipe;

typedef struct		map
{
	t_room			*road;
	int				size;
	struct s_road	*next;
}					t_map;


typedef struct		s_neigh
{
	t_room			*room;
	struct s_neigh	*next;
}					t_neigh;

typedef struct		s_data
{
	int		nbr_ant;
	t_room	*room;
	t_pipe	*pipe;
	t_room	*start;
	t_room	*end;
}					t_data;

#endif
