/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_tools.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:06:48 by basle-qu          #+#    #+#             */
/*   Updated: 2016/03/09 16:26:37 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TOOLS_H
# define STRUCT_TOOLS_H

t_room	*ft_add_room(t_room *room, char *line);
t_pipe	*ft_add_pipe(t_pipe *pipe, char *line);
int		find_room(t_room *room, char *str);
t_room	*end_room(t_room *room);

#endif
