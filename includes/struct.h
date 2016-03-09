/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 18:56:52 by basle-qu          #+#    #+#             */
/*   Updated: 2016/03/07 19:41:59 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_pipe
{
	char			*room_1;
	char			*room_2;
	struct s_pipe	*next;
}					t_pipe;

typedef struct		s_room
{
	char			*name;
	int				pos_x;
	int				pos_y;
	struct s_room	*next;
}					t_room;

typedef struct		s_data
{
	int		nbr_ant;
	t_room	*room;
	t_pipe	*pipe;
	char	*start;
	char	*end;
}					t_data;

#endif
