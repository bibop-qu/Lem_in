/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:08:30 by basle-qu          #+#    #+#             */
/*   Updated: 2016/03/11 12:04:00 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERIF_H
# define VERIF_H

int		verif_line_room(char *line);
int		ft_strform(char *str, int id);
int		verif_line_pipe(char *line, t_room *room);
int		exist_room(t_room *room, char *line);

#endif
